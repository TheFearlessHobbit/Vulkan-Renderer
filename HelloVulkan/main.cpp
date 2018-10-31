#include "Renderer.h"

int main() 
{
	Renderer myRenderer;

	try 
	{
		myRenderer.run();
	}
	catch (const std::exception& e) 
	{
		std::cerr << e.what() << "\n";
		return -1;
	}

	return 0;
}