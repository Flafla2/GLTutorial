#pragma once

#include <cstdint>

#include <GLFW/glfw3.h>

class Color {
public:
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 0;

	Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
	Color(float r, float g, float b) : r(r), g(g), b(b), a(1.0f) {}
	Color(uint32_t hex) {
		uint32_t a = (hex >> 24) & 0xff;
		uint32_t r = (hex >> 16) & 0xff;
		uint32_t g = (hex >> 8) & 0xff;
		uint32_t b = hex & 0xff;

		a = (float)a / 255.0f;
		r = (float)r / 255.0f;
		g = (float)g / 255.0f;
		b = (float)b / 255.0f;
	}

	void bindGL() {
		glColor4f(r, g, b, a);
	}

	Color operator*(Color& o) {
		return Color(r * o.r, g * o.g, b * o.b, a * o.a);
	}

};
