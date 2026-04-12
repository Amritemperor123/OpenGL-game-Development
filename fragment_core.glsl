#version 440

in vec3 vs_position;
in vec3 vs_color;
in vec3 vs_normal;

out vec4 fs_color;

uniform vec3 lightPos0;
uniform vec3 camPos;

void main()
{
	vec3 normal = normalize(vs_normal);
	vec3 lightDir = normalize(lightPos0 - vs_position);
	vec3 viewDir = normalize(camPos - vs_position);
	vec3 reflectDir = reflect(-lightDir, normal);

	vec3 ambient = 0.2f * vs_color;
	float diffuseStrength = max(dot(normal, lightDir), 0.0f);
	vec3 diffuse = diffuseStrength * vs_color;
	float specularStrength = pow(max(dot(viewDir, reflectDir), 0.0f), 32.0f);
	vec3 specular = 0.25f * specularStrength * vec3(1.0f);

	fs_color = vec4(ambient + diffuse + specular, 1.0f);
}
