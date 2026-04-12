#pragma once

#include <fstream>
#include <iostream>
#include <string>

struct ModelPlaceholder
{
	std::string sourcePath = "assets/models/placeholder.obj";
	std::string fallbackPath = "assets/models/placeholder.fbx";

	bool hasSourceFile() const
	{
		std::ifstream objFile(sourcePath);
		if (objFile.good())
		{
			return true;
		}

		std::ifstream fbxFile(fallbackPath);
		return fbxFile.good();
	}

	void printStatus() const
	{
		std::cout << "Model placeholder path: " << sourcePath << "\n";
		std::cout << "Alternate FBX path: " << fallbackPath << "\n";

		if (!hasSourceFile())
		{
			std::cout << "No imported model found yet. Rendering fallback cube until a loader is added.\n";
		}
	}
};
