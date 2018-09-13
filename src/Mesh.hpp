#pragma once

#include <string>
#include <vector>

#include <glm/vec3.hpp>

#include "Color.hpp"

class Mesh {
public:
	Mesh(std::string local_path);
	Mesh(std::vector<glm::vec3> verts, std::vector<int> tris);

	void draw();
private:
	std::vector<glm::vec3> verts;
	std::vector<int> tris;
};
