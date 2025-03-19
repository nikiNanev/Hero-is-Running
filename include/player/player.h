#ifndef PLAYER_H_
#define PLAYER_H_

#include "../scores/score.h"
#include "achievements.h"

#include <cstddef>
#include <iostream>

#include "player_profile.h"

class Player {
	unsigned int id;

	// Personal Info
	std::string firstName;
	std::string lastName;
	size_t age;

	//Player properties
	unsigned int health;
	float damage;
	float shieldPoints;
	float speed;

	PlayerProfile playerProfile(std::string name, std::string lastName);

	float jumpFactor;

	size_t enemyDown;
	
	Score scores;
	Achievements achievements;
public:
	Player(){};
	Player(unsigned int id, unsigned int health, float damage,
	       float shieldPoints, float speed, float jumpFactor);
	~Player(){};
	
	//Setters
	void setID(unsigned int id);
	void setHealth(unsigned int health);
	void setDamage(float damage);
	void setShieldPoints(float shieldPoints);
	void setSpeed(float speed);
	void setJumpFactor(float jumpFactor);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setAge(size_t age);
	
	//Getters
	unsigned int getID();
	unsigned int getHealth();
	float getDamage();
	float getShieldPoints();
	float getSpeed();
	float getJumpFactor();
	std::string getFirstName();
	std::string getLastName();
	size_t getAge();
	
};

#endif
