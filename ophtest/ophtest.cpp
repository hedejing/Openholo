#include "iostream"
#include "ophDepthMap.h"

using namespace std;

int main() {

	ophDepthMap* Hologram = new ophDepthMap();                                      // Create ophDepthMap instance
	Hologram->readConfig("config/TestSpecDepthMap.xml");                            // Read Config Parameters for Depth Map CGH
	Hologram->readImageDepth("source/DepthMap", "RGB_D", "D_D");                    // Load Depth and RGB image
	Hologram->setMode(MODE_GPU); //Select CPU or GPU Processing                     // Select CPU or GPU Processing
	Hologram->generateHologram();                                                   // CGH by depth map
	//Hologram->saveAsOhc("result/DepthMap/Result_DepthmapSample.ohc");               // Save to ohc(Openholo complex field file format)
	//Hologram->encodeHologram();                                                     // Encode Complex Field to Real Field
	Hologram->encoding(ophGen::ENCODE_TWOPHASE);                                                     // Encode Complex Field to Real Field
	Hologram->normalize();                                                          // Normalize Real Field to unsigned char(0~255) for save to image(*.BMP)
	Hologram->save("result/DepthMap/Result_DepthmapSample.bmp");                    // Save to bmp
	Hologram->release();

	return 0;
}