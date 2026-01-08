#pragma once

#include<iostream>
#include<string>

#include<glad/glad.h>
#include<glfw3.h>

#include<SOIL2/SOIL2.h>

class Texture
{
private:
	GLuint id;
	int height;
	int width;

public:
	Texture(const char* fileName, GLenum type)
	{
		unsigned char* image = SOIL_load_image(fileName, &this->width, &this->height, NULL, SOIL_LOAD_RGBA);

		glGenTextures(1, &this->id);
		glBindTexture(type, this->id);

		glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
		// MAG filter must be GL_LINEAR or GL_NEAREST
		glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// MIN filter can use mipmap filtering
		glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		if (image)
		{
			glTexImage2D(type, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(type);
		}
		else
		{
			std::cout << "ERROR::TEXTURE_LOAD_FAILED" << fileName << "\n";
		}

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(type, 0);
		SOIL_free_image_data(image);
	}

	~Texture()
	{
		glDeleteTextures(1, &this->id);
	}

	GLuint getID() const
	{
		return this->id;
	}

	void bind(GLint texture_unit, GLenum type)
	{
		glActiveTexture(GL_TEXTURE0 + texture_unit);
		glBindTexture(type, this->id);
	}

	void unBind(GLenum type)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(type, 0);
	}
};