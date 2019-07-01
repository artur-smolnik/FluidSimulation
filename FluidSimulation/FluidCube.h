#pragma once
#define IX(x, y, z) ((x) + (y) * N + (z) * N * N)

class FluidCube
{

	int size;
	float dt;
	float diff;
	float visc;

	float *s;
	float *density;

	float *Vx;
	float *Vy;
	float *Vz;

	float *Vx0;
	float *Vy0;
	float *Vz0;


public:

	FluidCube(int size, int diffusion, int viscosity, float dt);
	~FluidCube();

	void set_bnd(int b, float *x, int N);
	void lin_solve(int b, float *x, float *x0, float a, float c, int iter, int N);
	void diffuse(int b, float *x, float *x0, float diff, float dt, int iter, int N);
	void advect(int b, float *d, float *d0, float *velocX, float *velocY, float *velocZ, float dt, int N);
	void project(float *velocX, float *velocY, float *velocZ, float *p, float *div, int iter, int N);
	void FluidCubeStep();
	void FluidCubeAddDensity( int x, int y, int z, float amount);
	void FluidCubeAddVelocity(int x, int y, int z, float amountX, float amountY, float amountZ);

	float* getDensityArray() { return density; }
};

