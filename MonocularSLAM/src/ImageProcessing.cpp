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
 * File: ImageProcessing.cpp
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

#include <iostream>
#include <sstream>

#include "ImageProcessing.hpp"

ImageProcessing::ImageProcessing() : VSporadicActivity() {
	registerSubscriber(&imageSub, "ImageSub", "image", imageCallback);

	new_image = false;
//	image_msg_ptr = std::make_shared<star::sensor_msgs::Image>();
}

ImageProcessing::~ImageProcessing() {
}

void ImageProcessing::connectionCallback(std::string port, bool established, int num_connections) {
// ################ USER DEFINED BEGIN ##################
	std::cout << " " << std::endl;
	if(established)
		std::cout << port << " : ### Connected ###" << std::endl;
	else
		std::cout << port << " : ### DisConnected ###" << std::endl;
	std::cout << " " << std::endl;

// ################ USER DEFINED END ####################
}


void ImageProcessing::imageCallback(VariantActivity* va) {
	ImageProcessing* activity = (ImageProcessing*) va;

// ################ USER DEFINED BEGIN ##################
	std::cout << "ImageProcessing::imageCallback" << std::endl;
	// Take data
	star::sensor_msgs::Image image_msg;

	SampleInfo m_info;

	if(activity->imageSub.takeNextData(&image_msg, &m_info)) {
	    // ******************************
	    // *** de-serialize the image ***
	    // ******************************
		std::string encoding = image_msg.encoding();
		bool is_bigendian = image_msg.is_bigendian();
		int size = image_msg.step() * image_msg.height();

		unsigned char *bytes = new unsigned char[size];
		for(int i=0; i<size; i++)
			bytes[i] = image_msg.data()[i];

	    Mat frame = Mat(image_msg.height(), image_msg.width(), CV_8UC3, bytes).clone(); // make a copy
	    delete bytes;


	    // ******************************
	    // ***** display the image ******
	    // ******************************
	    namedWindow("Display Received Image", WINDOW_AUTOSIZE );
	    imshow("Display Received Image", frame);
	    waitKey(100);

		activity->new_image = true;
	}
// ################ USER DEFINED END ####################
}

void ImageProcessing::init() {
	std::cout << "[ImageProcessing]::init" << std::endl;
}

void ImageProcessing::setup() {
	std::cout << "[ImageProcessing]::setup" << std::endl;
}

void ImageProcessing::task() {
	std::cout << "[ImageProcessing]::task" << std::endl;
}

void ImageProcessing::quit() {
	std::cout << "[ImageProcessing]::quit()" << std::endl;
}


