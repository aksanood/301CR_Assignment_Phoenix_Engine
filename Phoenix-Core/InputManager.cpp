#include "InputManager.h"

namespace Phoenix {
	namespace Input {

		InputManager::InputManager() {}
		InputManager::~InputManager() {}

		void InputManager::pressKey(unsigned int ID)
		{
			m_keyMap[ID] = true;
		}
		void InputManager::releaseKey(unsigned int ID)
		{
			m_keyMap[ID] = false;
		}
		
		bool InputManager::isKeyPressed(unsigned int ID)
		{
			auto it = m_keyMap.find(ID);
			if (it != m_keyMap.end())
			{
				return it->second;
			}
			else
			{
				return false;
			}
		}


	}
}
