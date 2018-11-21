#include "Model.h"

CModel::CModel(COLORREF color) :
	color(color) {}

void CModel::set_bounding_box()
{
	vector<vec3> bounds(2);
	bool first = true;
	for (const CPolygon& polygon : polygons) {
		for (const vec3& point : polygon.vertices) {
			if (first) {
				bounds[0] = point;
				bounds[1] = point;
				first = false;
			}
			else {
				bounds[0].x = min(bounds[0].x, point.x);
				bounds[0].y = min(bounds[0].y, point.y);
				bounds[0].z = min(bounds[0].z, point.z);
				bounds[1].x = max(bounds[1].x, point.x);
				bounds[1].y = max(bounds[1].y, point.y);
				bounds[1].z = max(bounds[1].z, point.z);
			}
		}
	}

	// Define 8 points of the box
	bounding_box.clear();
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				bounding_box.push_back(vec3(bounds[i].x, bounds[j].y, bounds[k].z));
			}
		}
	}
}

void CModel::add_polygon(const CPolygon & polygon)
{
	polygons.push_back(polygon);
}

