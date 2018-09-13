#include <sstream>
#include <fstream>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Mesh.hpp"

Mesh::Mesh(std::vector<glm::vec3> verts, std::vector<int> tris) : verts(verts), tris(tris) {}

/** Mesh::Mesh(string local_path)
  * Loads a mesh from a file in .obj file format.  Only basic obj
  * constructs are supported -- do not export with UVs, normals,
  * or materials/material groups.
  *
  * local_path: path to the obj (local to executable)
  */
Mesh::Mesh(std::string local_path) {
	std::ifstream infile(local_path);

	std::string line;
	while (std::getline(infile, line))
	{
		if(line.find("v ") == 0) {
			line = line.substr(2, std::string::npos);
			std::istringstream iss(line);
			double x, y, z;
			if(iss >> x >> y >> z) {
				glm::vec3 v(x, y, z);
				verts.push_back(v);
			}
		} else if(line.find("f ") == 0) {
			line = line.substr(2, std::string::npos);
			std::istringstream iss(line);
			int v1, v2, v3;
			// only support triangles
			if(iss >> v1 >> v2 >> v3) {
				tris.push_back(v1);
				tris.push_back(v2);
				tris.push_back(v3);
			}
		}
	}

	infile.close();
}

void Mesh::draw() {
	glBegin(GL_TRIANGLES);
	auto i = tris.begin();
	while(i != tris.end()) {
		int i1 = *i; ++i;
		int i2 = *i; ++i;
		int i3 = *i; ++i;
		glm::vec3 v1 = verts[i1 - 1];
		glm::vec3 v2 = verts[i2 - 1];
		glm::vec3 v3 = verts[i3 - 1];

		glm::vec3 n = glm::cross(v3 - v1, v2 - v1);

		glNormal3f(n.x, n.y, n.z);
		glVertex3f(v1.x, v1.y, v1.z);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(v2.x, v2.y, v2.z);
		glNormal3f(n.x, n.y, n.z);
		glVertex3f(v3.x, v3.y, v3.z);
		
	}
	glEnd();
}