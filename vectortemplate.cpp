#include <stdio.h>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#define GLM_FORCE_RADIANS
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/matrix_inverse.hpp"

#include <iostream>

glm::vec3 WhatPartOfALivesInBDir( glm::vec3 a, glm::vec3 b )
{
   
    return normalize(b) * dot(a, normalize(b));

}


glm::vec3 WhatPartOfALivesPerpToB( glm::vec3 a, glm::vec3 b )
{
    return a - normalize(b) * dot(a, normalize(b));
}


glm::vec3 UnitSurfaceNormal( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
     return normalize(cross((r-q), (s-q)));
}


float Area( glm::vec3 q, glm::vec3 r, glm::vec3 s )
{
	 glm::vec3 n = cross((r-q), (s-q));
     //std::cout << n.x << " " << n.y << " " << n.z << std::endl;
     float l = length(n)/2;
     //std::cout << l << std::endl;
     return l;
}


bool IsPointInTriangle( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
    glm::vec3 n = cross((r-q), (s-q));
    glm::vec3 nq = cross((r-q), (p-q));
    glm::vec3 nr = cross((s-r), (p-r));
    glm::vec3 ns = cross((q-s), (p-s));

    if (dot(n, nq) > 0 && dot(n, nr) > 0 && dot(n, ns) > 0){
        return true;
    } else {
        return false;
    }
}



float DistanceFromPointToPlane( glm::vec3 q, glm::vec3 r, glm::vec3 s, glm::vec3 p )
{
    glm::vec3 n = cross((r-q), (s-q));
    n = normalize(n);
    return dot((p-q), n);
}


void WhoAmI( std::string &yourName, std::string &yourEmailAddress )
{
	yourName = "Andrew Snow";
	yourEmailAddress = "snowan@oregonstate.edu" ;
}

//THIS IS FOR TESTING PURPOSES ONLY
int main(){
  
  glm::vec3 a = glm::vec3(1, 2, 3);
  glm::vec3 b = glm::vec3(2, 2, 2);

  glm::vec3 x = WhatPartOfALivesInBDir(a, b);
  //std::cout << x.x << x.y << x.z << std::endl;
  
  x = WhatPartOfALivesPerpToB(a, b);
  //std::cout << x.x << x.y << x.z << std::endl;

  glm::vec3 c = glm::vec3(7, 8, 9);  
    
  x = UnitSurfaceNormal(a, b, c);
  //std::cout << x.x << x.y << x.z << std::endl;

  Area(a, b, c);
}
