﻿#include "ace.SideButton.h"

namespace ace{
	SideButton::SideButton(MouseButtonState mouseButtonState,bool doubleClicked)
	{
		m_mouseButtonState = mouseButtonState;
	}

	const MouseButtonState SideButton::GetButtonState() const
	{
		return m_mouseButtonState;
	}
};