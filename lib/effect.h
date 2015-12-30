#pragma once
#include <string>

#include <string>
#include <lib/token.h>
class Game;

// IEffect

class IEffect
{
public:
	virtual const std::string& Description() const = 0;
	virtual void Apply(Game& aGame) = 0;
  	~IEffect () {};
};

// IEffectFactory

class IEffectFactory
{
public:
	virtual IEffect* CreateEffect() = 0;
	~IEffectFactory() {}
};

// EffectNull

class EffectNull
	: public IEffect
{
public:
	EffectNull();
public:
	const std::string& Description() const override;
	void Apply(Game& aGame) override;
private:
	std::string iDescription;
};

class EffectFactoryNull
	: public IEffectFactory
{
public: // IEffectFactory
	IEffect* CreateEffect() override;
};


class EffectReceive
  : public IEffect
{
public:
  EffectReceive(int aReceived, Token aColour);
  ~EffectReceive();
public:
  const std::string& Description() const override;
  void Apply(Game& aGame) override;
private:
  int iReceived;
  std::string iDescription;
};

class EffectReceiveFactory
  : public IEffectFactory
{
public:
  EffectReceiveFactory(uint aPlayers); //EffectReceiveFactory needs to know the amount of players to appropriately generate receive amounts
  ~EffectReceiveFactory();
public: //IEffectFactory
  IEffect* CreateEffect() override;
private:
  uint iMaxReceive;
};
