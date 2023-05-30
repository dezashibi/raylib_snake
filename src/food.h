/***************************************************************************************
    File: food.h
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
#pragma once

#include "snake.h"


namespace Snake
{
	class Food
	{
	public:
		Food();

		~Food();

		void draw() const;

		const Vector2& position() noexcept;

	private:
		Vector2 m_position;
		Texture2D m_texture{};
	};
}
