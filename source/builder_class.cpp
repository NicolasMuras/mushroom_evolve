#include "builder_class.h"
#include <iostream>
#include <stdexcept>

#define PI 3.14159265358979324

BuilderClass::BuilderClass(Strain id)
{
	buildStrain(id);
}

// SET METHODS
void BuilderClass::setStage(int value)
{
	stage = value;
}
void BuilderClass::setLocation(float radio, float x, float y)
{
	X_Loc = x;
	Y_Loc = y;
	Radio_Loc = radio;
}
void BuilderClass::setTrunkColors(float r, float g, float b)
{
	red_trunk = r;
	green_trunk = g;
	blue_trunk = b;
}
void BuilderClass::setCapColors(float r, float g, float b)
{
	red_cap = r;
	green_cap = g;
	blue_cap = b;
}

// GET METHODS
int BuilderClass::getStage() const {
	return stage;
}

template <class generic>
generic BuilderClass::getRandomNumber(generic start, generic end) const
{
	std::random_device r;
	std::seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r() };

	std::mt19937 rng(seed);
	uniform_distribution<generic> dist(start, end);
	return dist(rng);
}

std::vector<unsigned int> BuilderClass::getIndices()
{
	return indices;
}
std::vector<unsigned int> BuilderClass::getCapIndices()
{
	return indices_cap;
}

// MAIN METHODS
void BuilderClass::buildStrain(Strain id)
{
	int shroom_type = id.getID();
	switch (shroom_type)
	{
	case(1):
		setLocation(getRandomNumber(0.1, 0.15), getRandomNumber(-2.0, 2.0), getRandomNumber(-2.0, 2.0));
		max_stage = getRandomNumber(18, 25);
		root_curvation_end = getRandomNumber(1, 2);
		cap_flatness = getRandomNumber(0.005, 0.01);
		curvation_start = getRandomNumber(2, 9);
		if (curvation_start > 7)
		{
			curvation_end = getRandomNumber((max_stage / 2), max_stage);
		}
		else {
			curvation_end = getRandomNumber((max_stage / 2) - 4, max_stage);
		}
		curvation_direction = getRandomNumber(0, 1);
		trunk_curvation_start = curvation_start;
		trunk_curvation_end = curvation_end;
		curvature_size = getRandomNumber(1, 2);
		min_trunk_width = getRandomNumber(3, 8);
		
		generateIndices(indices_cap, 12);
		setCapColors(id.getCapColor(0), id.getCapColor(1), id.getCapColor(2));
		setTrunkColors(id.getTrunkColor(0), id.getTrunkColor(1), id.getTrunkColor(2));
		break;
	case(2):
		setLocation(getRandomNumber(0.3, 0.7), getRandomNumber(-2.0, 2.0), getRandomNumber(-2.0, 2.0));
		max_stage = getRandomNumber(18, 25);
		root_curvation_end = getRandomNumber(2, 7);
		cap_flatness = getRandomNumber(0.04, 0.06);
		curvation_start = getRandomNumber(2, 9);
		if (curvation_start > 7)
		{
			curvation_end = getRandomNumber((max_stage / 2), max_stage);
		}
		else {
			curvation_end = getRandomNumber((max_stage / 2) - 4, max_stage);
		}
		curvation_direction = getRandomNumber(0, 1);
		trunk_curvation_start = curvation_start;
		trunk_curvation_end = curvation_end;
		curvature_size = getRandomNumber(1, 2);
		min_trunk_width = getRandomNumber(4, 8);
		
		generateIndices(indices_cap, 12);
		setCapColors(id.getCapColor(0), id.getCapColor(1), id.getCapColor(2));
		setTrunkColors(id.getTrunkColor(0), id.getTrunkColor(1), id.getTrunkColor(2));
		break;
	case(3):
		setLocation(getRandomNumber(0.4, 0.7), getRandomNumber(-2.0, 2.0), getRandomNumber(-2.0, 2.0));
		max_stage = getRandomNumber(14, 18);
		root_curvation_end = getRandomNumber(2, 3);
		cap_flatness = getRandomNumber(0.04, 0.05);

		curvation_start = max_stage;
		curvation_end = getRandomNumber((max_stage / 2) - 4, max_stage);
		curvation_direction = getRandomNumber(0, 1);
		trunk_curvation_start = curvation_start;
		trunk_curvation_end = curvation_end;
		curvature_size = 0.1;
		min_trunk_width = 8;

		generateIndices(indices_cap, 12);
		setCapColors(id.getCapColor(0), id.getCapColor(1), id.getCapColor(2));
		setTrunkColors(id.getTrunkColor(0), id.getTrunkColor(1), id.getTrunkColor(2));
		break;
	case(4):
		setLocation(getRandomNumber(0.1, 0.2), getRandomNumber(-2.0, 2.0), getRandomNumber(-2.0, 2.0));
		max_stage = getRandomNumber(18, 25);
		root_curvation_end = getRandomNumber(7, 10);
		cap_flatness = getRandomNumber(0.02, 0.04);
		curvation_start = getRandomNumber(2, 9);
		if (curvation_start > 7)
		{
			curvation_end = getRandomNumber((max_stage / 2), max_stage);
		}
		else {
			curvation_end = getRandomNumber((max_stage / 2) - 4, max_stage);
		}
		curvation_direction = getRandomNumber(0, 1);
		trunk_curvation_start = curvation_start;
		trunk_curvation_end = curvation_end;
		curvature_size = getRandomNumber(1, 2);
		min_trunk_width = getRandomNumber(3, 8);
		
		generateIndices(indices_cap, 12);
		setCapColors(id.getCapColor(0), id.getCapColor(1), id.getCapColor(2));
		setTrunkColors(id.getTrunkColor(0), id.getTrunkColor(1), id.getTrunkColor(2));
		break;
	default:
		std::cerr << "[!] INVALID SHROOM ID: (1 - 4)\n";
		break;
	}
	buildShroom();
	buildShroom();
}

void BuilderClass::buildShroom() // Build shrooms main function
{
	if (getStage() == 0)
	{
		
		for (int circle_stage = 0; circle_stage < 12; circle_stage++)
		{
			buildCapCircles(circle_stage);
		}
		generateColors();
		generateColorsCap();
	}
	if (getStage() < max_stage)
	{
		buildTrunk();
		setStage(getStage() + 1);
		generateIndices(indices, getStage());
	}
}

void BuilderClass::buildTrunk() // Implement random generated vars to build the shroom.
{
	float Z = 0.1; // Height multiplicator.
	if (getStage() < max_stage)
	{
		if (getStage() > curvation_start && getStage() < curvation_end) // Make translation in the circles of the trunk.
		{
			if (curvation_direction == 0) // Choose the direction
			{
				circle_translation -= ((curvation_end - curvation_start) / 10) * PI / (curvation_end - curvation_start) * curvature_size;
			}
			else
			{
				circle_translation += ((curvation_end - curvation_start) / 10) * PI / (curvation_end - curvation_start) * curvature_size;
			}
		}

		if (getStage() > curvation_end && getStage() < max_stage) // Reverse the translation in the circles of the trunk.
		{
			if (curvation_direction == 0) // Reverse direction.
			{
				circle_translation += ((max_stage - curvation_end) / 10) * PI / (23 - curvation_end) * curvature_size;
			}
			else
			{
				circle_translation -= ((max_stage - curvation_end) / 10) * PI / (23 - curvation_end) * curvature_size;
			}
		}

		if (getStage() < root_curvation_end) // Decremento gradual del radio en la raiz del hongo.
		{
			trunk_curvation += 0.4 * PI / (root_curvation_end); // El "0.4" y el "8" ajusta la suavidad del decremento, es ideal dividir PI por la cantidad de circulos que se veran afectado, este caso son 8 circulos.
		}

		if (getStage() > trunk_curvation_start && getStage() < trunk_curvation_end) // Decremento gradual del radio 20 - 23
		{
			if (Radio_Loc * (cos(trunk_curvation)) > (Radio_Loc / min_trunk_width))
			{
				trunk_curvation += 0.1 * PI / (trunk_curvation_end - trunk_curvation_start);
			}
		}

		float curved_translation_y = Y_Loc + Radio_Loc * (cos(trunk_curvation)) * sin(circle_translation);
		float curved_translation_x = X_Loc + Radio_Loc * (cos(trunk_curvation)) * cos(circle_translation);

		buildCircle(curved_translation_y, curved_translation_x,(Z * getStage()));
	}
}

void BuilderClass::buildCircle(float curved_translation_y, float curved_translation_x, float Z) // Build the circle with the current curved radius and translations.
{

	float angle = 0; // Angle parameter.
	//float inclination_y = 0;
	float inclination_z = 0;
	float Radio = Radio_Loc * (cos(trunk_curvation));
	static float rotation_var = 0;

	if (getStage() > curvation_start && getStage() < curvation_end)
	{
		if (curvation_direction == 0)
		{
			rotation_var -= 0.015;
		}
		else {
			rotation_var += 0.015;
		}
		
	}
	else if (getStage() > curvation_end && getStage() < max_stage)
	{
		if (curvation_direction == 0)
		{
			rotation_var += 0.015;
		}
		else {
			rotation_var -= 0.015;
		}
	}

	for (int i = 0; i < vertex_quantity; ++i)
	{
		if (getStage() > curvation_start && getStage() < curvation_end)
		{

			inclination_z = (Radio) * (sin(circle_inclination));

			if (curvation_direction == 0)
			{
				circle_inclination -= 2 * PI / 20;
			}
			else
			{
				circle_inclination += 2 * PI / 20;
			}
		}
		else if (getStage() > curvation_end && getStage() < max_stage)
		{
			inclination_z = (Radio) * (sin(circle_inclination));
			
			if (curvation_direction == 0)
			{
				circle_inclination += 2 * PI / 20;
			}
			else
			{
				circle_inclination -= 2 * PI / 20;
			}
		}

		// Cap follows the trunk
		z_inclinationCap(rotation_var, i);
		y_translateCap(curved_translation_y, i, angle);
		x_translateCap(curved_translation_x, i, angle);

		for (int j = 0; j < 3; ++j)
		{
			if (j == 0)
			{
				circle_group[getStage()][i][j] = (curved_translation_x + Radio * cos(angle));
			}
			else if(j == 1)
			{
				circle_group[getStage()][i][j] = (curved_translation_y + Radio * sin(angle));
			}
			else if(j == 2)
			{
				circle_group[getStage()][i][j] = Z + (inclination_z * rotation_var);
			}

		}
		
		angle += 2 * PI / vertex_quantity;
	}
}

void BuilderClass::z_inclinationCap(float rotation, int vertex)
{
	float Z = cap_flatness;
	for (int i = 0; i < 12; ++i)
	{
		cap_group[i][vertex][2] = (getStage() * 0.1) + (Z * i) + ((cap_radius[i] * sin(circle_inclination)) * rotation);
	}
}

void BuilderClass::y_translateCap(float y_curvation, int vertex, float angle) // This translate the shroom cap on Y axis.
{
	for (int i = 0; i < 12; ++i)
	{
		cap_group[i][vertex][1] = y_curvation + cap_radius[i] * sin(angle);
	}
}

void BuilderClass::x_translateCap(float x_curvation, int vertex, float angle) // This translate the shroom cap on Y axis.
{
	for (int i = 0; i < 12; ++i)
	{
		cap_group[i][vertex][0] = x_curvation + cap_radius[i] * cos(angle);
	}
}

void BuilderClass::buildCapCircles(int &circle_stage) // Build cap circles main function, set the radius curvature of the cap circles.
{

	float Z = cap_flatness;

	if (circle_stage == 0)
	{
		cap_curvation += 0.5 * PI / 4;
		cap_radius[circle_stage] = Radio_Loc / 2;
		buildCapCircle(circle_stage, Radio_Loc / 2, (Z * circle_stage));
	}
	if (circle_stage > 0 && circle_stage < 12)
	{
		cap_curvation += 0.8 * PI / 11;
		cap_radius[circle_stage] = Radio_Loc * (sin(cap_curvation));
		buildCapCircle(circle_stage, cap_radius[circle_stage], (Z * circle_stage));
	}
	
}

void BuilderClass::buildCapCircle(int &circle_stage, float Radio, float Z) // Build the current cap circle with the given parameters.
{

	float t = 0; // Angle parameter.

	for (int i = 0; i < vertex_quantity; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (j == 0)
			{
				cap_group[circle_stage][i][j] = X_Loc + Radio * cos(t);
			}
			else if (j == 1)
			{
				cap_group[circle_stage][i][j] = Y_Loc + Radio * sin(t);
			}
			else
			{
				cap_group[circle_stage][i][j] = Z;
			}

		}
		t += 2 * PI / vertex_quantity;
	}
}

void BuilderClass::generateIndices(std::vector<unsigned int> &indices_pointer, int actual_stage = 12)
{
	int faces = ((20 * (actual_stage - 1) * 2) * 3) + 6;
	indices_pointer.resize(faces);

	int elIndex = 0;
	indices_pointer[elIndex] = 19;
	indices_pointer[elIndex + 1] = 0;
	indices_pointer[elIndex + 2] = 20;

	indices_pointer[elIndex + 3] = 20;
	indices_pointer[elIndex + 4] = 0;
	indices_pointer[elIndex + 5] = 21;
	elIndex += 6;

	for (int i = 0; i < actual_stage - 1; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if(elIndex < faces - 9) {
				// Split the quad into two triangles
				indices_pointer[elIndex] = i * 20 + j;
				indices_pointer[elIndex + 1] = i * 20 + j + 1;
				indices_pointer[elIndex + 2] = (i + 1) * 20 + j +1;

				indices_pointer[elIndex + 3] = (i + 1) * 20 + j +1;
				indices_pointer[elIndex + 4] = i * 20 + j + 1;
				indices_pointer[elIndex + 5] = (i + 1) * 20 + j + 2;

				elIndex += 6;
			}
			else if (elIndex >= faces - 9)
			{
				indices_pointer[elIndex - 1] = (i + 1) * 20 + j - 18;
				indices_pointer[elIndex - 2] = i * 20 + j;
				indices_pointer[elIndex - 3] = (i + 1) * 20 + j;

				indices_pointer[elIndex] = i * 20 + j;
				indices_pointer[elIndex + 1] = i * 20 + j + 1 - 20;
				indices_pointer[elIndex + 2] = (i + 1) * 20 + j;

				indices_pointer[elIndex + 3] = (i + 1) * 20 + j;
				indices_pointer[elIndex + 4] = i * 20 + j + 1 - 20;
				indices_pointer[elIndex + 5] = (i + 1) * 20 + j + 2 - 20;

				elIndex += 6;
			}
		}
	}
}
void BuilderClass::generateColors()
{

	for (int i = 0; i < max_stage - 1; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			colors_group[i][j][0] = red_trunk * (i * 2);
			colors_group[i][j][1] = green_trunk * (i * 2);
			colors_group[i][j][2] = blue_trunk * (i * 2);
		}
	}
}
void BuilderClass::generateColorsCap()
{

	for (int i = 0; i < 12 - 1; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			cap_colors[i][j][0] = red_cap * (i * 0.3);
			cap_colors[i][j][1] = green_cap * (i * 0.3);
			cap_colors[i][j][2] = blue_cap * (i * 0.3);
		}
	}
}


// Aditional methods
void BuilderClass::showGuides() const  // Draw the mushroom in the window
{
	for (int i = 0; i <= getStage(); ++i)
	{
		glBegin(GL_LINE_LOOP);
		glColor3f(0.1 * getStage(), 0.0, 0.0);
		for (int j = 0; j < 20; ++j)
		{
			glVertex3f(circle_group[i][j][0], circle_group[i][j][1], circle_group[i][j][2]);
		}
		glEnd();
		glFlush();
	}

	for (int k = 0; k < 12; ++k)
	{

		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.1 * getStage());
		for (int j = 0; j < 20; ++j)
		{
			if (k > 11) {
				continue;
			}
			glVertex3f(cap_group[k][j][0], cap_group[k][j][1], cap_group[k][j][2]);

		}
		glEnd();
		glFlush();
	}
}
void BuilderClass::showBuilderInfo() // Set variables that generate variations on the mushroom geometry
{
	std::cout << "----------------------- MUSHROOM-INFO ----------------------- \n";
	std::cout << "max_stage: " << max_stage << '\n';
	std::cout << "root_curvation_end: " << root_curvation_end << '\n';
	std::cout << "curvation_start: " << curvation_start << '\n';
	std::cout << "curvation_end: " << curvation_end << '\n';
	std::cout << "curvation_direction: " << curvation_direction << '\n';
	std::cout << "trunk_curvation_start: " << trunk_curvation_start << '\n';
	std::cout << "trunk_curvation_end: " << trunk_curvation_end << '\n';
	std::cout << "curvature_size: " << curvature_size << '\n';
	std::cout << "min_trunk_width: " << min_trunk_width << '\n';
	std::cout << "cap_flatness: " << cap_flatness << '\n';
}

/*
COLORS: 0.1 * i, 0.02 * i, 0.03 * i
*/
