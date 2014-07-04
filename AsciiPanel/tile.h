#include <Windows.h>

class Tile
{
public:
	static enum ColorValue
	{
		BLACK = 0,
		DARK_BLUE = 1,
		DARK_GREEN = 2,
		DARK_TEAL = 3,
		DARK_RED = 4,
		DARK_PINK = 5,
		DARK_YELLOW = 6,
		WHITE = 7,
		GRAY = 8,
		BLUE = 9,
		GREEN = 10,
		TEAL = 11,
		RED = 12,
		PINK = 13,
		YELLOW = 14
	} Color;

	Tile(char glyph_, ColorValue color_)
	{
		glyph = glyph_;
		color = color_;
	}

	Tile() : Tile('.', WHITE) { }

	char getGlyph() { return glyph; }
	void setGlyph(char glyph_) { glyph = glyph_; }
	int getColor() { return color; }
	void setColor(ColorValue color_) { color = color_; }

protected:
	char glyph;
	unsigned int color;
};