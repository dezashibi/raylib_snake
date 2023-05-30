/***************************************************************************************
    File: snake.cpp
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

#include "snake.h"

using namespace Game;

void Snake::draw()
{
	for (unsigned i{ 0 }; i < m_body.size(); ++i)
	{
		auto x = m_body[i].x;
		auto y = m_body[i].y;
		auto segment = Rectangle{ x * Config::cell_size, y * Config::cell_size,
								  Config::cell_size, Config::cell_size };
		DrawRectangleRounded(segment, 0.5, 6, Config::game_theme.secondary);
	}
}

void Snake::update()
{
	m_body.push_front(Vector2Add(m_body[0], m_direction));

	if (m_add_segment)
	{
		m_add_segment = false;
		return;
	}

	m_body.pop_back();

}

const std::deque<Vector2>& Snake::body() noexcept
{
	return m_body;
}

void Snake::set_direction(float x, float y)
{
	m_direction.x = x;
	m_direction.y = y;
}

void Snake::set_direction(Vector2 dir)
{
	m_direction.x = dir.x;
	m_direction.y = dir.y;
}

const Vector2& Snake::direction() noexcept
{
	return m_direction;
}

void Snake::add_segment()
{
	m_add_segment = true;
}

void Snake::reset()
{
	m_body = { Vector2{ 6, 9 }, Vector2{ 5, 9 }, Vector2{ 4, 9 }};
	m_direction = { 1, 0 };
	m_add_segment = false;
}
