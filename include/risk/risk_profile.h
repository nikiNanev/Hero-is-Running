#ifndef RISK_PROFILE_H_
#define RISK_PROFILE_H_

#include <cstddef>
#include "../player/player.h"

class RiskProfile
{
	size_t scale;
	size_t riskTaken;
	Player player;
public:
	RiskProfile();
	RiskProfile(Player player, size_t scale, size_t riskTaken);
	~RiskProfile() {};

	// Setters
	void setScale(size_t scale);
	void setRiskTaken(size_t riskTaken);

	// Getters
	size_t getScale();
	size_t getRiskTaken();
};

#endif
