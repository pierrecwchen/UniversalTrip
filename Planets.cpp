#include "Planets.h"
#include <cmath>


// Determine whether the distance between two point is less than the addition of their radius or not by giving two center point and radius.
bool Planets::isDistanceLessThanTwoRadius(  Point &centerOfPlanet1, float radiusOfPlanet1,
											Point &centerOfPlanet2, float radiusOfPlanet2 )
{

	bool isLess = false;


	float distanceBetweenTwoPoints = static_cast<float>( sqrt( pow( (centerOfPlanet1.getXCoordinate() - centerOfPlanet2.getXCoordinate() ), 2 ) +
															   pow( (centerOfPlanet1.getYCoordinate() - centerOfPlanet2.getYCoordinate() ), 2 ) +
															   pow( (centerOfPlanet1.getZCoordinate() - centerOfPlanet2.getZCoordinate() ), 2 ) ) );
	

	if( ( distanceBetweenTwoPoints - radiusOfPlanet1 - radiusOfPlanet2 ) < 0.00001f){

		isLess = true;

	}


	return isLess;

}


// Determine whether there is a exist planet in the area.
bool Planets::isOccupied(Point &centerOfPlanet, float radiusOfPlanet){
	
	if( centerOfPlanet.getXCoordinate() >= 0 ){

		if( centerOfPlanet.getYCoordinate() >= 0 ){
			
			// X>=0, Y>=0, Z>=0.
			if( centerOfPlanet.getZCoordinate() >= 0 ){

				for( int i = 0; i < static_cast<int>( posPosPosLocation.size() ); i++ ){

					if( isDistanceLessThanTwoRadius( centerOfPlanet, radiusOfPlanet, posPosPosLocation.at(i), posPosPosRadius.at(i) ) ){
						return true;
					}

				}

			}

			// X>=0, Y>=0, Z<0.
			else{

				for(int i = 0; i < static_cast<int>( posPosNegLocation.size() ); i++){

					if( isDistanceLessThanTwoRadius( centerOfPlanet, radiusOfPlanet, posPosNegLocation.at(i), posPosNegRadius.at(i) ) ){
						return true;
					}
				
				}
			
			}
		}

		else{

			// X>=0, Y<0, Z>=0.
			if( centerOfPlanet.getZCoordinate() >= 0 ){

				for(int i = 0; i < static_cast<int>( posNegPosLocation.size() ); i++ ){

					if( isDistanceLessThanTwoRadius( centerOfPlanet, radiusOfPlanet, posNegPosLocation.at(i), posNegPosRadius.at(i) ) ){
						return true;
					}
				
				}
			
			}

			// X>=0, Y<0, Z<0.
			else{

				for(int i = 0; i < static_cast<int>( posNegNegLocation.size() ); i++ ){

					if( isDistanceLessThanTwoRadius( centerOfPlanet, radiusOfPlanet, posNegNegLocation.at(i), posNegNegRadius.at(i) ) ){
						return true;
					}
				
				}
			
			}
		
		}
	
	}
	
	else{

		if( centerOfPlanet.getYCoordinate() >= 0 ){

			// X<0, Y>=0, Z>=0.
			if( centerOfPlanet.getZCoordinate() >= 0 ){

				for(int i = 0; i < static_cast<int>( negPosPosLocation.size() ); i++ ){

					if( isDistanceLessThanTwoRadius(centerOfPlanet, radiusOfPlanet, negPosPosLocation.at(i), negPosPosRadius.at(i) ) ){
						return true;
					}
				
				}
			
			}

			// X<0, Y>=0, Z<0.
			else{

				for(int i = 0; i < static_cast<int>( negPosNegLocation.size() ); i++ ){

					if( isDistanceLessThanTwoRadius( centerOfPlanet, radiusOfPlanet, negPosNegLocation.at(i), negPosNegRadius.at(i) ) ){
						return true;
					}
				
				}
			
			}
		
		}

		else{

			// X<0, Y<0, Z>=0.
			if( centerOfPlanet.getZCoordinate() >= 0){

				for(int i = 0; i < static_cast<int>( negNegPosLocation.size() ); i++ ){

					if( isDistanceLessThanTwoRadius( centerOfPlanet, radiusOfPlanet, negNegPosLocation.at(i), negNegPosRadius.at(i) ) ){
						return true;
					}
				
				}
			
			}

			// X<0, Y<0, Z<0.
			else{

				for(int i = 0; i < static_cast<int>( negNegNegLocation.size() ); i++ ){

					if( isDistanceLessThanTwoRadius( centerOfPlanet, radiusOfPlanet, negNegNegLocation.at(i), negNegNegRadius.at(i) ) ){
						return true;
					}
				
				}
			
			}
		
		}
	
	}

	return false;
}


// Add an planet into the list.
void Planets::setPlanetInfomation(Point &centerOfPlanet, float radiusOfPlanet){
	
	if( centerOfPlanet.getXCoordinate() >= 0 ){
		
		if( centerOfPlanet.getYCoordinate() >= 0 ){
			
			// X>=0, Y>=0, Z>=0.
			if( centerOfPlanet.getZCoordinate() >= 0 ){
				
				posPosPosLocation.push_back( centerOfPlanet );
				posPosPosRadius.push_back( radiusOfPlanet );

			}

			// X>=0, Y>=0, Z<0.
			else{

				posPosNegLocation.push_back( centerOfPlanet );
				posPosNegRadius.push_back( radiusOfPlanet );

			}

		}

		else{

			// X>=0, Y<0, Z>=0.
			if( centerOfPlanet.getZCoordinate() >= 0 ){

				posNegPosLocation.push_back( centerOfPlanet );
				posNegPosRadius.push_back( radiusOfPlanet );

			}

			// X>=0, Y<0, Z<0.
			else{

				posNegNegLocation.push_back( centerOfPlanet );
				posNegNegRadius.push_back( radiusOfPlanet );
			
			}
		
		}
	
	}
	
	else{

		if( centerOfPlanet.getYCoordinate() >= 0 ){

			// X<0, Y>=0, Z>=0.
			if( centerOfPlanet.getZCoordinate() >= 0 ){

				negPosPosLocation.push_back( centerOfPlanet );
				negPosPosRadius.push_back( radiusOfPlanet );

			}

			// X<0, Y>=0, Z<0.
			else{

				negPosNegLocation.push_back( centerOfPlanet );
				negPosNegRadius.push_back( radiusOfPlanet );

			}

		}

		else{

			// X<0, Y<0, Z>=0.
			if( centerOfPlanet.getZCoordinate() >=0 ){

				negNegPosLocation.push_back( centerOfPlanet );
				negNegPosRadius.push_back( radiusOfPlanet );

			}

			// X<0, Y<0, Z<0.
			else{

				negNegNegLocation.push_back( centerOfPlanet );
				negNegNegRadius.push_back( radiusOfPlanet );

			}
		
		}

	}

}