#include <stdio.h>

#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

// My own "binary format" for displaying data from file
// File starts with header of metadata, then the data until EOF
/* 
   +---------------------------------------------------------------+
   | time_created (timestamp in epoch milliseconds)                |
   +---------------------------------------------------------------+
   | name                                                          |
   +---------------------------------------------------------------+
   | range_min                                                     |
   +---------------------------------------------------------------+
   | range_max                                                     |
   +---------------------------------------------------------------+
   | data (timestamp in epoch milliseconds + value)                |
   +---------------------------------------------------------------+

*/

int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	// Create the window and OpenGL context
	InitWindow(1280, 800, "Hello Raylib");
	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	//SearchAndSetResourceDir("resources");
	// Load a texture from the resources directory
	//Texture wabbit = LoadTexture("wabbit_alpha.png");
	
	// game loop
	while (!WindowShouldClose())		// run the loop until the user presses ESCAPE or presses the Close button on the window
	{
		// drawing
		BeginDrawing();
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(BLACK);
		// draw some text using the default font
		//DrawText("Hello Raylib", 200,200,20,WHITE);
		// draw our texture to the screen
		//DrawTexture(wabbit, 400, 200, WHITE);
		for(int i = 100; i < 200; i++){
			DrawLine(100, i, 300, i, RED);
		}
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our texture so it can be cleaned up
	//UnloadTexture(wabbit);
	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
