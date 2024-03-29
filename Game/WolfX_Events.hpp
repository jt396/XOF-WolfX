#ifndef WOLFX_EVENTS_HPP
#define WOLFX_EVENTS_HPP


#include "../GameplayFoundations/XOF_Event.hpp"
#include <glm/vec3.hpp>


// Temporary, switch to hashed strings
enum WOLFX_EVENTS {
	PLAYER_SPAWNED = 0,
	PLAYER_MOVED,
	PLAYER_PRESSED_ACTION_KEY,
	PLAYER_PRESSED_FIRE_KEY,
	WOLF_X_EVENTS_COUNT,
};


struct PlayerSpawnedEvent : public Event {
	PlayerSpawnedEvent() { type = WOLFX_EVENTS::PLAYER_SPAWNED; }
};

struct PlayerMovedEvent : public Event {
	enum ARGS {
		TRANSLATION = 0,
		YAW,
		PITCH,
	};

	PlayerMovedEvent( glm::vec3 translation = glm::vec3( 0.f, 0.f, 0.f ), 
		float yaw = 0.f, float pitch = 0.f ) { 
		type = WOLFX_EVENTS::PLAYER_MOVED;
		
		arguments[TRANSLATION].asVec3f[0] = translation.x;
		arguments[TRANSLATION].asVec3f[1] = translation.y;
		arguments[TRANSLATION].asVec3f[2] = translation.z;
		arguments[YAW].asFloat = yaw;
		arguments[PITCH].asFloat = pitch;
	}
};

struct PlayerPressedActionKeyEvent : public Event {
	enum ARGS {
		PLAYER_POS = 0,
	};

	PlayerPressedActionKeyEvent( const glm::vec3& playerPos ) { 
		type = WOLFX_EVENTS::PLAYER_PRESSED_ACTION_KEY;

		arguments[PLAYER_POS].asVec3f[0] = playerPos.x;
		arguments[PLAYER_POS].asVec3f[1] = 0.f; // y isn't used in WolfX
		arguments[PLAYER_POS].asVec3f[2] = playerPos.z;
	}
};

struct PlayerPressedFireKeyEvent : public Event {
	// Damage to deal arg?
	PlayerPressedFireKeyEvent() {
		type = WOLFX_EVENTS::PLAYER_PRESSED_FIRE_KEY;
	}
};

#endif // WOLFX_EVENTS_HPP
