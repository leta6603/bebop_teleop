#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "Events.h"
#include "GUI.h"
#include <SDL2/SDL.h>
#include <sensor_msgs/Image.h>

class Window : Listener {
public:
	Window(bool&);
	Window(void);
	~Window(void) noexcept;
	Window(const Window& other) = delete;
	Window(Window && other) = delete;
	void event(SDL_Event*);
	void update(void);
	void destroy(void);
	bool ok(void);
	void makeGUI(void);

	void updateVideoTexture(const sensor_msgs::ImageConstPtr&);

	static std::string font_path;
private:
	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_Texture* video;
	sensor_msgs::Image image;
	TTF_Font* font;
	bool video_dirty = false;
	bool alive = false;
	bool init(void);

	// Window(const Window&);
};

extern Window* window;

#endif
