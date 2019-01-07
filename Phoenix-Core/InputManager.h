#pragma once
#include <unordered_map>

namespace Phoenix {
	namespace Input {

		class InputManager {

		private:
			std::unordered_map<unsigned int, bool> m_keyMap;
		public:
			InputManager();
			~InputManager();

			void pressKey(unsigned int ID);
			void releaseKey(unsigned int ID);
			bool isKeyPressed(unsigned int ID);

		};
	}
}
