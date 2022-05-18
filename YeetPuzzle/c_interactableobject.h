#pragma once















namespace puzzle {
	namespace objects {
		class c_interactableobject {
		public:
			virtual void on_enter_hover() = 0;
			virtual void on_leave_hover() = 0;

			virtual bool is_hovering(POINT p) = 0;

			bool is_hovering_v = false;
		};
	}
}