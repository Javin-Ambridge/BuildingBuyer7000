#include <string>
#include <iostream>
#include "game.h"
using namespace std;

Game::Game(View *v){
	view = v;
	generator = new RandomGenerator();
	currentRollupCups = 0;
	board[0] = new CollectOSAP("Collect OSAP");
	board[1] = new PropertyTile("AL");
	board[2] = new SLC("SLC");
	board[3] = new PropertyTile("ML");
	board[4] = new Tuition("Tuition");
	board[5] = new PropertyTile("MKV");
	board[6] = new PropertyTile("ECH");
	board[7] = new NeedlesHall("Needles Hall");
	board[8] = new PropertyTile("PAS");
	board[9] = new PropertyTile("HH");
	board[10] = new DCTimsLine("DC Tims Line");
	board[11] = new PropertyTile("RCH");
	board[12] = new Gym("PAC");
	board[13] = new PropertyTile("DWE");
	board[14] = new PropertyTile("CPH");
	board[15] = new PropertyTile("UWP");
	board[16] = new PropertyTile("LHI");
	board[17] = new SLC("SLC");
	board[18] = new PropertyTile("BMH");
	board[19] = new PropertyTile("OPT");
	board[20] = new GooseNesting("Goose Nesting");
	board[21] = new PropertyTile("EV1");
	board[22] = new NeedlesHall("Needles Hall");
	board[23] = new PropertyTile("EV2");
	board[24] = new PropertyTile("EV3");
	board[25] = new PropertyTile("V1");
	board[26] = new PropertyTile("PHYS");
	board[27] = new PropertyTile("B1");
	board[28] = new Gym("CIF");
	board[29] = new PropertyTile("B2");
	board[30] = new GoToTims("Go To Tims");
	board[31] = new PropertyTile("EIT");
	board[32] = new PropertyTile("ESC");
	board[33] = new SLC("SLC");
	board[34] = new PropertyTile("C2");
	board[35] = new PropertyTile("REV");
	board[36] = new NeedlesHall("Needles Hall");
	board[37] = new PropertyTile("MC");
	board[38] = new CoopFee("Coop Fee");
	board[39] = new PropertyTile("DC");
	for(int i = 0; i < 8; i++)
		players[i] = NULL;
}

void Game::auction(Tile *t, int playerNotIncluded){
	int p = this->getNumberOfPlayers() - 1;
	int playersIncluded[p];
	int pos = 0;
	for(int i = 0; i < p; i++){
		if(i != playerNotIncluded && players[i] != NULL){
			playersIncluded[pos] = i;
			pos++;
		}
	}
	cout << "The following tile is now up for auction: " << t->getName() << endl;
	int playersLeft = p;
	int currentBid = 1;
	while(true){
		if(playersLeft == 1)
			break;
		for(int i = 0; i < p; i++){
			if(playersLeft == 1)
				break;
			if(playersIncluded[i] != -1){
				cout << "It is " << players[playersIncluded[i]]->getName() << " turn to make a bid." << endl;
				string input;
				cout << "Would you like to withdraw from this bidding? Type 'withdraw'or 'continue'" << endl;
				cin >> input;
				while(input != "withdraw" || input != "continue"){
					cout << "You entered an invalid command. Enter either 'withdraw' or 'continue'" << endl;
					cin >> input;
				}
				if(input == "withdraw"){
					playersIncluded[i] = -1;
					playersLeft--;
					continue;
				}
				cout << "You have chosen to bid. Place a bid which is higher than $" << currentBid << endl;
				int bid;
				cin >> bid;
				while(bid <= currentBid){
					cout << "You entered a bid that is lower, or equal to the previous bid. Try again." << endl;
					cin >> bid;
				}
				currentBid = bid;
				cout << "You have just placed the bid of $" << currentBid << endl;
			}
		}
	}
	int finalBidder;
	for(int i = 0; i < p; i++){
		if(playersIncluded[i] != -1){
			finalBidder = i;
			break;
		}
	}
	cout << "Congragulations to " << players[playersIncluded[finalBidder]]->getName() << " you have won the auction with the bid of $" << currentBid << endl;
	cout << players[playersIncluded[finalBidder]]->getName() << " now owns " << t->getName() << endl;
	if(players[playersIncluded[finalBidder]]->subMoney(currentBid) == false){
		notEnoughMoney(currentBid, playersIncluded[finalBidder]);
		if(players[playersIncluded[finalBidder]]->getBankrupt())
			return;
	}
	players[playersIncluded[finalBidder]]->addProperty(*t);
	cout << "Players new balance is: $" << players[playersIncluded[finalBidder]]->getMoney() << endl;
}

void Game::notEnoughMoney(int balanceNeeded, int playerIndex){	
	cout << "Looks like you don't have enough money! Time to sell somestuff, or declare bankruptcy." << endl;
	cout << "Enter what you would like to do: Declare banckruptcy (bankrupt), trade (trade), mortgage (mortgage) or sell improvements (simprovements)" << endl;
	while(true){
		string input;
		cin >> input;
		while(input != "bankrupt" || input != "trade" || input != "mortgage" || input != "simprovements"){
			cout << "You entered something invalid. Try again. Enter any of bankrupt/trade/mortgage/simprovements" << endl;
			cin >> input;
		}
		if(input == "bankrupt"){

		}
		if(input == "trade"){

		}
		if(input == "mortgage"){

		}
		if(input == "simprovements"){

		}
		if(players[playerIndex]->getMoney() >= balanceNeeded){
			cout << "Good job, you have enough money!" << endl;
			break;
		}
		if(players[playerIndex]->getBankrupt()){
			cout << "Looks like your bankrupt and out of the game." << endl;
			break;
		}
	}
}

void Game::bankrupt(){

}

void Game::trade(){

}

void Game::mortgage(){

}

void Game::buyImprovement(string tileName){

}

void Game::sellImprovement(string tileName){

}

bool Game::isActive(){
	return active;
}

void Game::addPlayer(string name, string piece){
	for(int i = 0; i < 8; i++){
		if(players[i] == NULL){
			players[i] = new Player(name, piece);
			players[i]->updatePos(*board[0]);
			return;
		}
	}
}

int Game::playerWhoOwns(Tile *t){
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){
			if(players[i]->hasProperty(*t))
				return i;
		}
	}
	return -1;
}

void Game::doMove(int playerIndex){
	Player *currentPlayer = players[playerIndex];
	bool hasRolled = false;
	int doublesRolled = 0;
	bool justGotOutOfDCLine = false;
	while(true){
		string command;
		cout << endl;
		if(doublesRolled == 0 && justGotOutOfDCLine == false){			
			cout << "Please enter a valid command:" << endl;
			cin >> command;
		}else{
			command = "roll";
		}
		if(command == "roll"){
			if(hasRolled){
				cout << "You have already rolled, you cannot use this command this turn." << endl;
				continue;
			}			
			int currentPosition = currentPlayer->getPos()->getIndex();
			if(currentPlayer->getDCTimsLine() == 0 && justGotOutOfDCLine == false){	
				cout << "Rolling two dice right now!" << endl;			
				int roll1 = generator->getDiceRoll(); 
				int roll2 = generator->getDiceRoll();
				cout << "You rolled a " << roll1 << " for you first roll, and a " << roll2 << " for your second roll." << endl;
				if(roll1 == roll2 && doublesRolled == 2){
					cout << "UHOH you rolled 3 doubles in a row! That means you are going to the DC Tims Line!" << endl;
					currentPlayer->setLastDieRoll(roll1 + roll2);
					currentPlayer->updatePos(*board[10]);
					hasRolled = true;
					doublesRolled = 0;
					continue;
				}
				if(roll1 == roll2){
					cout << "You just rolled a double, you get to roll again after you do whatever action is for this turn." << endl; 
					doublesRolled++;
				}else{
					doublesRolled = 0;
				}
				int rollNum = roll1 + roll2;
				currentPlayer->setLastDieRoll(rollNum);
				currentPosition = currentPosition + rollNum;
			}else if(currentPlayer->getDCTimsLine() != 0 && justGotOutOfDCLine == false){
				cout << "Rolling two dice to see if you get a double, so you get leave the DC Tims line." << endl;
				int roll1 = generator->getDiceRoll();
				int roll2 = generator->getDiceRoll();
				cout << "You rolled a " << roll1 << " on your first roll, and a " << roll2 << " on the second roll." << endl;
				if(roll1 == roll2){
					cout << "You got a double! Thats pretty lucky! You are now not in the DC Tims Line." << endl;
					currentPosition = currentPosition + roll1 + roll2;
				}else{
					cout << "You didnt roll a double.. Looks like your still in the Tims Line. " << endl;
					currentPlayer->setLastDieRoll(roll1 + roll2);
				}
			}else{
				cout << "Using you last roll, which is: " << currentPlayer->getLastDieRoll() << endl;
				currentPosition = currentPosition + currentPlayer->getLastDieRoll();
			}
			if(currentPosition > 39){
				cout << "----------------------------------------------------------------------" << endl;
				cout << "Congragulations you have passed collect OSAP (or landed on it), you gain $200!" << endl;
				currentPlayer->addMoney(200);
				cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				cout << "----------------------------------------------------------------------" << endl;
				currentPosition = currentPosition - 40;
			}
			Tile *currentTile = board[currentPosition];
			currentPlayer->updatePos(*currentTile);
			bool DCTimsLineFromSLC = false;
			if(currentTile->getName() == "SLC"){
				if(currentRollupCups < 4){
					if(generator->wonRollupCup()){
						cout << "Congragulations you have won a Rollup the Rim Cup! Thats pretty lucky!" << endl;
						currentPlayer->addRollUpCup();
						currentRollupCups++;
						cout << "You now have " << currentPlayer->getRollUpCup() << " roll up cups." << endl;
						cout << "Your turn is up now." << endl;
						hasRolled = true;
						continue;
					}
				}
				int changeOfPos = currentTile->getMove(generator->getSLCRoll());
				if(changeOfPos == 23){
					cout << "SLC probabilities have moved you to the DC Tims Line... Unfortunate.." << endl;
					currentPosition = 10;
					currentPlayer->setDCTimsLine(1);
					DCTimsLineFromSLC = true;
				}
				else if(changeOfPos == 24){
					cout << "SLC probabilities have moved you to colled OSAP! Thats lucky...." << endl;
					currentPosition = 0;
					cout << "----------------------------------------------------------------------" << endl;
					cout << "Congragulations you have landed on Collect OSAP, you gain $200!" << endl;
					currentPlayer->addMoney(200);
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
					cout << "----------------------------------------------------------------------" << endl;
				}else{
					cout << "SLC probabilities have move you this many spaces: " << changeOfPos << endl;
					currentPosition = currentPosition + changeOfPos;
				}
				if(currentPosition > 39){
					cout << "----------------------------------------------------------------------" << endl;
					cout << "Congragulations you have passed collect OSAP, you gain $200!" << endl;
					currentPlayer->addMoney(200);
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
					cout << "----------------------------------------------------------------------" << endl;
					currentPosition = currentPosition - 40;
				}
				currentTile = board[currentPosition];
				currentPlayer->updatePos(*currentTile);				
			}
			if(currentTile->getName() == "Go To Tims"){
				cout << "You have landed on Go To Tims, your are being sent to the DC Tims Line... Sorry..." << endl;
				currentPlayer->setDCTimsLine(1);
				hasRolled = true;
				continue;
			}
			if(currentTile->getName() == "Coop Fee"){
				cout << "UHOH! You landed on coop fee." << endl;
				if(currentPlayer->subMoney(currentTile->getTuition()) == false){
					notEnoughMoney(150, playerIndex);
					if(currentPlayer->getBankrupt())
						return;
				}
				cout << "$150 has been removed from your account" << endl;
				cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				hasRolled = true;
				continue;
			}
			if(currentTile->getName() == "Tuition"){
				cout << "Looks like you need to pay some tuition, this is either $300 or 10% of your total savings." << endl;
				int savingsPay = currentPlayer->getNetWorth();
				cout << "To help your decision, here is 10% of your savings: $" << savingsPay << endl;
				cout << "So if you want to pay the $300 enter $300 or if you want to pay the 10% enter 10%" << endl;
				string input;
				cin >> input;
				while(input != "$300" || input != "10%"){
					cout << "You entered something incorrect. Try again. ($300 or 10%)" << endl;
					cin >> input;
				}
				if(input == "$300"){
					cout << "You chose to pay the $300" << endl;
					if(currentPlayer->subMoney(300) == false){
						notEnoughMoney(300, playerIndex);
						if(currentPlayer->getBankrupt())
							return;
					}
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;	
				}else{	
					cout << "You chose to pay the 10%, which is $" << savingsPay << endl;
					if(currentPlayer->subMoney(savingsPay) == false){
						notEnoughMoney(savingsPay, playerIndex);
						if(currentPlayer->getBankrupt())
							return;
					}
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				}
				hasRolled = true;
				continue;
			}
			if(currentTile->getName() == "Collect OSAP"){
				cout << "You have landed on Collect OSAP, there is nothing to do." << endl;
				hasRolled = true;
				continue;
			}
			if(currentTile->getName() == "Goose Nesting"){
				cout << "You have landed on Goose Nesting, there is nothing to do." << endl;
				hasRolled = true;
				continue;
			}
			if(currentTile->getName() == "DC Tims Line"){
				if(currentPlayer->getDCTimsLine() == 0){
					cout << "You landed on DC Tims line, luckily you arent in it!" << endl;
					hasRolled = true;
					continue;
				}else{
					cout << "You are in the DC Tims line... You need to do something!" << endl;
					if(DCTimsLineFromSLC == false)
						currentPlayer->setDCTimsLine(currentPlayer->getDCTimsLine() + 1);
					int currentTurn = currentPlayer->getDCTimsLine();
					cout << "It is your " << currentTurn << " turn in the DC Tims Line" << endl;
					if(currentTurn == 4){
						cout << "This is your last turn in the line, you need to pay $50 or use a rollup the rim cup" << endl;
						if(currentPlayer->getRollUpCup() == 0){
							cout << "Sadly you dont have any Roll up the rim cups, so you need to pay $50" << endl;
							if(currentPlayer->subMoney(50) == false){
								notEnoughMoney(50, playerIndex);
								if(currentPlayer->getBankrupt())
									return;
							}
							cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
							hasRolled = true;
							currentPlayer->setDCTimsLine(0);
							justGotOutOfDCLine = true;
							continue;
						}else{
							cout << "Looks like you have a Roll up the rim cup." << endl;
							cout << "If you would like to pay the $50 enter $50, or if you want to use the roll up the rim cup enter Rollup" << endl;
							string input;
							cin >> input;
							while(input != "$50" || input != "Rollup"){
								cout << "You entered something incorrectly. Try again. Either $50 or Rollup" << endl;
								cin >> input;
							}
							if(input == "$50"){
								cout << "You chose to spend the $50" << endl;
								if(currentPlayer->subMoney(50) == false){
									notEnoughMoney(50, playerIndex);
									if(currentPlayer->getBankrupt())
										return;
								}	
								cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
							}else{
								cout << "You chose to use a rollup the rim cup." << endl;
								currentPlayer->removeRollUpCup();
								cout << "You have " << currentPlayer->getRollUpCup() << " roll up the rim cups left." << endl;
							}
							currentPlayer->setDCTimsLine(0);
							hasRolled = true;
							justGotOutOfDCLine = true;
							continue;
						}
					}else{
						cout << "It is not your last turn in the DC Tims line." << endl;
						cout << "You can either wait, pay $50, or use a rollup the rim cup (You have " << currentPlayer->getRollUpCup() << " cups left)" << endl;
						if(currentPlayer->getRollUpCup() == 0){
							string input;
							cout << "Looks like you don't have any rollup the rim cups. So choose either to Wait or Pay $50 (Wait/$50)" << endl;
							cin >> input;
							while(input != "Wait" || input != "$50"){
								cout << "You entered something incorrectly, please enter either Wait or $50" << endl;
								cin >> input;
							}
							if(input == "Wait"){
								cout << "You chose to wait." << endl;
								hasRolled = true;
								continue;
							}else{
								cout << "You chose to spend the $50 and get out of the line." << endl;
								if(currentPlayer->subMoney(50) == false){
									notEnoughMoney(50, playerIndex);
									if(currentPlayer->getBankrupt())
										return;
								}
								cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
								hasRolled = true;
								currentPlayer->setDCTimsLine(0);
								justGotOutOfDCLine = true;
								continue;
							}
						}else{
							cout << "Please enter either Wait/$50/Rollup to choose you next move" << endl;
							string input;
							cin >> input;
							while(input != "Wait" || input != "$50" || input != "Rollup"){
								cout << "You entered something incorrectly, please enter either Wait or $50 or Rollup" << endl;
								cin >> input;
							}
							if(input == "Wait"){
								cout << "You chose to wait." << endl;
								hasRolled = true;
								continue;
							}else if(input == "$50"){
								cout << "You chose to spend $50 and get out of the DC tims line." << endl;
								if(currentPlayer->subMoney(50) == false){
									notEnoughMoney(50, playerIndex);
									if(currentPlayer->getBankrupt())
										return;
								}
								cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
								hasRolled = true;
								currentPlayer->setDCTimsLine(0);
								justGotOutOfDCLine = true;
								continue;
							}else{
								cout << "You chose to use a rollup the rim cup." << endl;
								currentPlayer->removeRollUpCup();
								cout << "You have " << currentPlayer->getRollUpCup() << " roll up the rim cups left." << endl;
								hasRolled = true;
								currentPlayer->setDCTimsLine(0);
								justGotOutOfDCLine = true;
								continue;
							}
						}
					}
				}
			}
			if(currentTile->getName() == "Needles Hall"){ 
				if(currentRollupCups < 4){
					if(generator->wonRollupCup()){
						cout << "Congragulations you have won a Rollup the Rim Cup! Thats pretty lucky!" << endl;
						currentPlayer->addRollUpCup();
						currentRollupCups++;
						cout << "You now have " << currentPlayer->getRollUpCup() << " roll up cups." << endl;
						cout << "Your turn is up now." << endl;
						hasRolled = true;
						continue;
					}
				}
				int moneyChange = currentTile->getMoneyChange(generator->getNeedlesRoll());
				if(moneyChange > 0){
					cout << "Congragulations you just won $" << moneyChange << " from Needles Hall!" << endl;
					currentPlayer->addMoney(moneyChange);
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				}else{
					moneyChange = moneyChange * -1;
					cout << "UHOH! You unfortunately lost $" << moneyChange << " at Needles Hall.." << endl;
					if(currentPlayer->subMoney(moneyChange) == false){
						notEnoughMoney(moneyChange, playerIndex);
						if(currentPlayer->getBankrupt())
							return;
					}
					cout << "Your new balance is: $" << currentPlayer->getMoney() << endl;
				}
				hasRolled = true;
				continue;
			}
			if(currentTile->isBuyable()){
				cout << "Looks like this property: " << currentTile->getName() << " is purchasable!" << endl;
				cout << "Would you like to purchase it? The cost of the property is: " << currentTile->getPurchaseCost() << ". Yes/No" << endl;
				string input;
				cin >> input;
				while(input != "Yes" || input != "No"){
					cout << "Invalid input. Please enter Yes or No." << endl;
					cin >> input;
				}
				if(input == "Yes"){
					//Need to check for invalid amount of money here.
					int purchaseCost = currentTile->getPurchaseCost();
					if(currentPlayer->subMoney(purchaseCost) == false){
						notEnoughMoney(purchaseCost, playerIndex);
						if(currentPlayer->getBankrupt())
							return;
					}
					currentPlayer->addProperty(*currentTile);
					currentTile->setBuyable(false);
					cout << "Congragulations you have just purchased " << currentTile->getName() << endl;
					cout << "Your current balance is now " << currentPlayer->getMoney() << endl;
					hasRolled = true;
					continue; //Need to update the view before this.
				}else{
					auction(currentTile, playerIndex); //Need to update the view after this.
				}
			}else{
				//Need to check that the person has enough money to pay the other player.
				cout << "UHOH! Someone owns this property, you need to pay them!" << endl;
				int playerOwner = playerWhoOwns(currentTile);
				cout << "You are paying " << players[playerOwner]->getName() << " this much money: $" << currentTile->getTuition() << endl;
				int payableMoney = currentTile->getTuition();
				players[playerOwner]->addMoney(payableMoney);
				if(currentPlayer->subMoney(payableMoney) == false){
					notEnoughMoney(payableMoney, playerIndex);
					if(currentPlayer->getBankrupt())
						return;
				}
				cout << "Your current balance is now: " << currentPlayer->getMoney() << endl;
				hasRolled = true;
				continue; //Need to update the view before this.
			}
		}
		if(command == "next"){

		}
		if(command == "trade"){
			trade();
		}
		if(command == "improve"){
			string input;
			cin >> input; //Property to be bought or sold.
			string buyOrSell;
			cin >> buyOrSell;
			if(buyOrSell == "buy"){
				buyImprovement(input);
			}else if(buyOrSell == "sell"){
				sellImprovement(input);
			}else{
				//Not entered something correctly.
			}
		}
		if(command == "mortgage"){
			mortgage();
		}
		if(command == "unmortgage"){

		}
		if(command == "bankrupt"){
			bankrupt();
		}
		if(command == "assets"){

		}
		if(command == "save"){

		}
	}
}

void Game::setNumberOfPlayers(int num){
	numberOfPlayers = num;
}

int Game::getNumberOfPlayers(){
	return numberOfPlayers;
}

bool Game::isPieceUsed(string piece){
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL){
			if(players[i]->getPiece() == piece)
				return true;
		}
	}
	return false;
}

Tile *Game::getPosition(int playerIndex){
	return players[playerIndex]->getPos();
}

Game::~Game(){
	for(int i = 0; i < 40; i++)
		delete board[i];
	for(int i = 0; i < 8; i++){
		if(players[i] != NULL)
			delete players[i];
	}
	delete generator;
}
