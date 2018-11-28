#pragma once
#include "Mat.h"

class CCamera
{
public:
	mat4 transform;
	mat4 projection;
	vec4 position;
	float top, bottom, left, right;
	float _near, _far;
	bool is_ortho;

	CCamera();
	CCamera(const CCamera& camera);
	void set_orthographic();
	void set_perspective();
	bool is_orthographic() const;
};

