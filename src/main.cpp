#include "Material.h"
#include "Scene.h"
#include "Sphere.h"
#include "PpmWriter.h"
#include <vector>

int main() {
	Material blue(Vec3f(0.05, 0.05, 0.4));
	Material yellow(Vec3f(0.6, 0.6, 0.05));
	Material background(Vec3f(0.05, 0.1, 0.15));

	std::vector<Sphere> spheres {
		{Vec3f( 4, 1, -20), 8, blue},
		{Vec3f( -3, 0, -10), 2, yellow}
	};
	
	LightPoint light(Vec3f(-17, -4, 10), 1.8);

	Scene scene(spheres, light, background);
	auto result = scene.render(1920, 1080);

	PpmWriter writer;
	writer.write(result, "./results.ppm", 1920, 1080);

	return 0;
}
