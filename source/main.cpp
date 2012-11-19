#include "f_exception.hpp"
#include "include_gl.hpp"
#include <SFML\Window.hpp>
#include "flog.hpp"
#include "event_test_object.hpp"
#include "event.hpp"
#include "level_manager.hpp"
#include <sstream>
#include "flog_format.hpp"

int main()
{
	ft::Flog &penis = ft::Flog::out();
	ft::Flog::out().flogInit();
	ft::Flog::out().setColor(ft::BLUE | ft::INTENSITY);
	ft::Flog::out().openLog(false);
	ft::Flog::out().setLogMode(ft::CON_LOG);

	//ft::Flog::getInstance()->setLogMode(ft::LogMode::CONSOLE);

	system("pause");
	//sig.connect(&aplusb);
	//sig();
	sf::ContextSettings settings;
	sf::Window window;
	window.create(sf::VideoMode(800,800,32),"SFML Window test",sf::Style::Default,settings);
	sf::Event event;		

	GLenum err;
	err = glewInit();
	if(err == GLEW_OK)
	{
	}
	else
	{
		const unsigned char* errorStr = glewGetErrorString(err);
		stringstream s;
		s << errorStr;
		string penis = s.str();
	}
	
	// Set color and depth clear value
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Black Background
	glClearDepth(15.0f);								// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();  // this call was already there.
	// left, right, bottom, top
	glOrtho(-10.0f, 10.0f, -10.0f, 10.0f, -10.0f, 10.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//gluPerspective(45.0f, 640.0f / 480.0f, 0.1f, 100.0f);
	// this causes the square to rotate
	glLoadIdentity();  // hard headed: calling glLoadIdentity again.
	glRotatef(60,1,0,0);
	glRotatef(45,0,0,1);

	LevelManager levelManager(NULL);
	levelManager.loadLevel("testLevel.txt");
	levelManager.setActiveLevel("testLevel.txt");
	
	try
	{
    // run the main loop
	bool running = true;
    while (running)
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
	            // end the program
                running = false;
            }
            else if (event.type == sf::Event::Resized)
            {
	            // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		levelManager.renderLevel();
		window.display();
    }
		
		//while(ft::ImageCache::discardBottomImage() > 0);
		
	}
	
	catch(ft::FException& fe)
	{
		std::cout << fe.what() << std::endl;
		system("pause");
	}
	catch(std::exception &e)
	{
			
		std::cout << e.what() << std::endl;
		system("pause");
	}
	
	return EXIT_SUCCESS;
}


