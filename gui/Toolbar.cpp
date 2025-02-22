#include "Toolbar.hpp"

Toolbar::Toolbar(const char* path)
{
	pathE = new TextElement(path, 20, 0, MONOSPACED);
	pathE->position(10, 10);
	elements.push_back(pathE);
	this->path = path;

	SDL_Color white = { 0xFF, 0xFF, 0xFF, 0xFF };

	// toolbar actions
	// TODO: make real touchable buttons, move handler logic here
	actions = new TextElement("(-) Exit    (+) Save    (x) Copy    (y) Paste    (l/r) Select    (b) Delete    (a) Type", 18, &white);
	actions->position(620, 10);

	keyActions = new TextElement("(-) Exit    (+) Save    (x) Caps    (y) Stow Keyboard    (b) Backspace    (a) Type", 18, &white);
	keyActions->position(610, 10);
}

void Toolbar::setModified(bool modified)
{
	this->modified = modified;

	std::string text;
	text += path;
	text += (modified ? "*" : "");
	pathE->textSurface = pathE->renderText(text, 20, MONOSPACED, 0);

	// TODO: have TextElement easier to update...
	int w, h;
	SDL_QueryTexture(pathE->textSurface, NULL, NULL, &w, &h);
	pathE->width = w;
	pathE->height = h;
}

void Toolbar::render(Element* parent)
{
	SDL_Rect background = { 0, 0, 1280, 50 };

	// draw top bar on top of other things
	SDL_SetRenderDrawColor(parent->renderer, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderFillRect(parent->renderer, &background);

	super::render(this);

	if (keyboardShowing)
		keyActions->render(this);
	else
		actions->render(this);
}