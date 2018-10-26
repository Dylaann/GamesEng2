#ifndef COMPONENT_H
#define COMPONENT_H

#include <utility>

/// <summary>
/// Component Interface
/// </summary>
class Component {
public:
	int id = 0;
	virtual ~Component() {}

};

/// <summary>
/// Health Component.
/// </summary>
class HealthComponent : public Component {
public:
	HealthComponent() : m_health(100) { id = 1; };

	int getHealth() { return m_health; };
	void setHealth(int health) { m_health = health; };

private:
	int m_health;

};

/// <summary>
/// Position Component.
/// </summary>
class PositionComponent : public Component {
public:
	PositionComponent(std::pair<float, float> pos) : m_position(pos) { id = 2; };

	std::pair<float, float> getPos() { return m_position; };
	void setPos(std::pair<float, float> pos) { m_position = pos; };

private:
	std::pair<float, float> m_position;
};

/// <summary>
/// Control Component.
/// </summary>
class ControlComponent : public Component {
public:
	ControlComponent() { id = 3; };

	enum DirectionState {
		Idle,
		Left,
		Right,
		Up,
		Down
	};

	void changeState(DirectionState state) {
		m_currentGameState = state;
	};

	DirectionState m_currentGameState = DirectionState::Right;
};

#endif // !COMPONENT_H

