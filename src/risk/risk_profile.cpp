#include "../../include/risk/risk_profile.h"

RiskProfile::RiskProfile()
{

}

RiskProfile::RiskProfile(Player player, size_t scale, size_t riskTaken) : player(player), scale(scale), riskTaken(riskTaken)
{

}

//Setters
void RiskProfile::setScale(size_t scale){
	this->scale = scale;
}

void RiskProfile::setRiskTaken(size_t riskTaken){
	this->riskTaken = riskTaken;
}

//Getters
size_t RiskProfile::getScale(){
	return this->scale;
}

size_t RiskProfile::getRiskTaken(){
	return this->riskTaken;
}
