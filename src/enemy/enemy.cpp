#include "../../include/enemy/enemy.h"

Enemy::Enemy(size_t id, std::string name, size_t type, size_t level){
	this->id = id;
	this->name = name;
	this->type = type;
	this->level = level;
	
	//Spawn one enemy ( to do )
	this->spawn();
}

Enemy::~Enemy()
{
	
}

void Enemy::spawn(){
	//Wave wave = new Wave();
	this->wave.setID(1);
	
	std::cout << "Enemy wave: " << this->wave.getID() << std::endl;
	std::cout << "Spawn one enemy" << std::endl;
}

void Enemy::setID(size_t id){
	this->id = id;
}

void Enemy::setName(std::string name){
	this->name = name;
}

void Enemy::setType(size_t type){
	this->type = type;
}

void Enemy::setLevel(size_t level){
	this->level = level;
}

size_t Enemy::getID(){
	return this->id;
}

std::string Enemy::getName(){
	return this->name;
}

size_t Enemy::getType(){
	return this->type;
}

size_t Enemy::getLevel(){
	return this->level;
}
