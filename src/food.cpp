/***************************************************************************************
    File: food.cpp
    Author: Navid Dezashibi
    Initial Creation Date: 2023-05-30
    Contact: navid@dezashibi.com
    Website: https://dezashibi.com
    License:
    Please refer to the LICENSE file, repository or website for more information about
    the licensing of this work. If you have any questions or concerns,
    please feel free to contact me at the email address provided above.
 ***************************************************************************************   
    << OTHER DESCRIPTIONS >>
 **************************************************************************************/
#include "food.h"

using namespace Snake;

Food::Food()
{
	Image image = LoadImage("assets/images/food.png");
	m_texture = LoadTextureFromImage(image);
	UnloadImage(image);
}

Food::~Food()
{
	UnloadTexture(m_texture);
}

void Food::draw() const
{
	DrawTexture(m_texture, m_position.x * Config::cell_size, m_position.y * Config::cell_size, WHITE);
}

const Vector2& Food::position() noexcept
{
	return m_position;
}