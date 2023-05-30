/***************************************************************************************
    File: values.h
    Author: Navid Dezashibi
    Initial Creation Date: 2023-05-30
    Contact: navid@dezashibi.com
    Website: https://dezashibi.com
    License:
    Please refer to the LICENSE file, repository or website for more information about
    the licensing of this work. If you have any questions or concerns,
    please feel free to contact me at the email address provided above.
 ***************************************************************************************   
    Constant values and configs
 **************************************************************************************/
#pragma once

#include "game.h"

#include "raymath.h"
#include <deque>

namespace Game
{
	class Snake
	{
	public:
		void draw();

		void update();

		const std::deque<Vector2>& body() noexcept;

	private:
		std::deque<Vector2> m_body{ Vector2{ 6, 9 }, Vector2{ 5, 9 }, Vector2{ 4, 9 }};
		Vector2 m_direction = { 1, 0 };
	};

}