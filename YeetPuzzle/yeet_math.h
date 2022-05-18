#pragma once

















namespace yeet {
	class yeetvec3 {
	public:
		float x = 0, y = 0, z = 0;
	};

	class yeetvec2 {
	public:
		inline yeetvec2() {}
		inline yeetvec2(float x1, float y1) : x(x1), y(y1) {}
		float x = 0, y = 0;

		inline yeetvec2& operator=  (const yeetvec2& other) { x = other.x; y = other.y; return *this; }
	};

	class yeetvec4 {
	public:
		inline yeetvec4() {}
		inline yeetvec4(float x1, float y1, float z1, float w1) : x(x1), y(y1), z(z1), w(w1) {}
		float x = 0, y = 0, z = 0, w = 0;

		inline yeetvec4& operator=  (const yeetvec4& other) { x = other.x; y = other.y; z = other.z; w = other.w; return *this; }

	};
}