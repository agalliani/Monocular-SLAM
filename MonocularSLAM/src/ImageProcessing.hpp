/********************************************************************************
 *
 * ImageProcessing
 *
 * Copyright (c) 2020
 * All rights reserved.
 *
 * Davide Brugali, Università degli Studi di Bergamo
 *
 * -------------------------------------------------------------------------------
 * File: ImageProcessing.hpp
 * Created: September 8, 2020
 * Author: <A HREF="mailto:brugali@unibg.it">Davide Brugali</A>
 * -------------------------------------------------------------------------------
 *
 * This software is published under a dual-license: GNU Lesser General Public
 * License LGPL 2.1 and BSD license. The dual-license implies that users of this
 * code may choose which terms they prefer.
 *
 * -------------------------------------------------------------------------------
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  - Neither the name of the University of Bergamo nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 2.1 of the
 * License, or (at your option) any later version or the BSD license.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License LGPL and the BSD license for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL and BSD license along with this program.
 *
 ******************************************************************************
 */
#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <star/core/runtime/VSporadicActivity.hpp>
#include <star/core/runtime/VFunctionality.hpp>
#include <star/core/runtime/VProperty.hpp>
#include <star/core/runtime/VPublisher.hpp>
#include <star/core/runtime/VSubscriber.hpp>

#include "sensor_msgsPubSubTypes.h"

#include <boost/thread/mutex.hpp>

#include <opencv2/opencv.hpp>

using namespace cv;

class ImageProcessing : public VSporadicActivity {
public:
	ImageProcessing();
	~ImageProcessing();
	void connectionCallback(std::string port, bool established, int num_connections);
	static void imageCallback(VariantActivity* va);

protected:
	void init();
	void setup();
	void task();
	void quit();

private:
	VSubscriber<star::sensor_msgs::ImagePubSubType> imageSub;

	SampleInfo_t m_info;

// ################ USER DEFINED BEGIN ##################
	bool new_image;
//	std::shared_ptr<star::sensor_msgs::Image> image_msg_ptr;

// ################ USER DEFINED END ####################
};
  

#endif
