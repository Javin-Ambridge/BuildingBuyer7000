#ifndef COLLECTOSAP_H
#define COLLECTOSAP_H
#include "tile.h"

class CollectOSAP: public Tile {
		public:
		CollectOSAP(std::string name);
		virtual ~CollectOSAP();
		virtual bool improveAmount(int improves);
		virtual std::string getName();
		virtual bool isBuyable();
		virtual bool isEvent();
		virtual int getTuition();
		virtual int getPurchaseCost();
		virtual int getImprovementCost();
		virtual std::string getMonopolyBlock();
		virtual int getIndex();
};


#endif
