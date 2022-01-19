#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//loads images declared in header, with image assets from src folder of this project
	testImg.load("ned.jpg");
	
	// loads fonts, same as the image above but for fonts (styles, sizes)
	smallTxt.load("Dongle-Light.ttf", 16);
	medTxt.load("Dongle-Regular.ttf", 17);
	bigTxt.load("RobotoCondensed-Regular.ttf", 17);
	btnTxt.load("Dongle-Bold.ttf", 26);
	uiHeader.load("Dongle-Bold.ttf", 55); 

	//button setting
	btn1.set(10, 70, 350, 60); // 10 and 50 as x and y coordinates, 350 and 60 as length and width
	btn2.set(10, 140, 350, 60); // same except the y value is incremented by 70 to arrange in a column
	btn3.set(10, 210, 350, 60);
	btn4.set(10, 280, 350, 60);
	btn5.set(10, 350, 350, 60);
	btn6.set(10, 420, 350, 60);
	btn7.set(10, 490, 350, 60);
	btn8.set(10, 560, 350, 60);
	btn9.set(10, 630, 350, 60);
	btn10.set(10, 700, 350, 60);

	queWindow.set(0, 60, 370, 760); // num are as follows, Xposition, Yposition, Length, Width 
	resWindow.set(390, 20, 615, 925); // original width value is 725
	
	//countWindow.set(390, 20, countWindowLength, 50);
	loadData(); //function to load the data is summoned
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(108, 184, 235); // sets color to lightish blue
	
	

	ofSetColor(228, 241, 255); // sets color to offwhite
	ofDrawRectangle(queWindow);


	ofSetColor(101, 119, 134); // sets color to gray
	ofDrawRectangle(resWindow); // draws resWindow as a rectangle
	ofDrawRectangle(btn1); 
	ofDrawRectangle(btn2);
	ofDrawRectangle(btn3);
	ofDrawRectangle(btn4);
	ofDrawRectangle(btn5);
	ofDrawRectangle(btn6);
	ofDrawRectangle(btn7);
	ofDrawRectangle(btn8);
	ofDrawRectangle(btn9);
	ofDrawRectangle(btn10); // draws the btn entities on the screen using ofDrawRectangle




	ofSetColor(255, 255, 255);
	uiHeader.drawString("Tweet Finder", 30, 45); // uses uiHeader object for drawString function, Tweet Search string, 30 x and 45 y added as values
	btnTxt.drawString("Count Tweets", 105, 110);  // same but with adjusted string, x and y values to put text in the btn entities drawn 
	btnTxt.drawString("Count Tweets w/ 'money'", 50, 180);
	btnTxt.drawString("Count Tweets w/ 'politics'", 48, 250);
	btnTxt.drawString("Print Tweets w/ 'Paris'", 65, 320);
	btnTxt.drawString("Print Tweets w/ 'DreamWorks'", 27, 390);
	btnTxt.drawString("Print Tweets w/ 'Uber'", 65, 460);
	btnTxt.drawString("Count Tweets w/ 'Trump'", 60, 530);
	btnTxt.drawString("Count Tweets w/ 'Pizza'", 60, 600);
	btnTxt.drawString("Print Tweets w/ 'Tokyo'", 60, 670);
	btnTxt.drawString("Print Tweets w/ 'America'", 55, 740);
	
	int yPos = 120;
	

	for (int q = 0; q < tweets.size(); q++) {

		bigTxt.drawString(tweetDate[q], 395, yPos); // draws the value of the current element of TweetDate

		string formattedTxt = wrapString(tweets[q], 580); // declares new string formattedTxt, which is equal to the wrapString function with the current element of tweets and value 580 passed in
		smallTxt.drawString(formattedTxt, 400, (yPos + 20)); //  using smallTxt, calls drawString with formattedTxt, 400 (x position) and yPos incremented by 20 passed in

		yPos += 110; // increments yPos by 110;
		if (q == (tweets.size() - 1) && displayTweetCount == true) { // if code that runs if displayTweetCount is equal to true and q is equal to the second to last element
			
			countWindow.set(390, 20, countWindowLength, 50); // sets countWindow rectangle with a dynamic length value
			ofSetColor(170, 184, 194); // sets color to lighter grey
			ofDrawRectangle(countWindow); // draws countWindow rectangle 
			ofSetColor(20, 23, 26); // sets color to white
			btnTxt.drawString("Tweets: " + ofToString(tweetCount), 405, 50); // draws the value of tweetCount using ofToString and btnTxt.drawString
		}

	}
	

	//testImg.draw(600, 500, 212, 212);
}

//--------------------------------------------------------------
void ofApp::loadData() {
	data.open(ofToDataPath("sampleTweets.csv")); // uses data to open sampleTweets.csv (itself accessed via ofToDataPath as the file is located in bin/src
	if (data.is_open()) { // if statement that runs as long as data is open
		while (!data.eof()) { // while loop that runs as long as its not the end of data file

			getline(data, dateOfTweet, ','); // gets the first part of a row in the csv file into dateOfTweet string, ends at ,
			getline(data, b, 'b'); // gets the b in the row to b string, ends at itself
			getline(data, tweetContent); // gets the remaining parts to tweetContent

			processTweet1.push_back(dateOfTweet);
			processTweet2.push_back(tweetContent); // pushes the values back into their appropriate vectors
		}
		processTweet1.erase(processTweet1.begin()); // erases the first element in tweet1 which is a row with irrelevant information
		data.close(); //close file
	}
	else { // else statement that runs if anything else happens, usually failure to find the csv
		cout << "Error: File not found." << endl; // outputs error message
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == '1') { // runs if 1 key is pressed
		displayTweetCount = false; // returns displayTweetCount to false, removing any previous displayed count of tweets
		tweets.clear();
		tweetDate.clear(); // clears any remaining elements in both vectors before further operation in this if statement
		std::cout << "Clicked button 1" << std::endl; // displays appropriate message to console

		for (int a = 0; a < 1550; a++) { // for loop that runs as long as a is less than the 1550, ergo it displays the first 1550 columns

			tweets.push_back(processTweet2[a]);
			tweetDate.push_back(processTweet1[a]); // pushes the values of processTweet1 and processTweet2 into tweets and tweetDate vectors

		}

		tweetCount = 63694; // sets tweetCount to 63694 (the number of data lines in the csv) as passing and displaying every single row in the csv file will crash the app
		countWindowLength = 190; // sets countWindowLength to 190
		displayTweetCount = true; // resets displayTweetCount to true to make it count its own number of tweets

		int tweetNum = 0;
		for (int a = 0; a < processTweet2.size(); a++) { // for loop that runs as long as a is less than the size of processTweet2, displaying all the tweets
			tweetNum++;
			//std::cout << processTweet1[a] << " " << processTweet2[a] << std::endl;
		}
		std::cout << "The total amount of tweets in sampleTweets.csv is " << tweetNum << std::endl; // displays every tweet in the csv file to console using cout 
	}
	else if (key == '2') {  // runs if 2 key is pressed
		std::cout << "Clicked button 2" << std::endl; // displays appropriate message to console
		displayTweetCount = false;
		tweets.clear();
		tweetDate.clear();

		processData("money", "Money"); // summons processData function with "money" and "Money" passed in as parameter
		countWindowLength = 160;
		displayTweetCount = true;
	}
	else if (key == '3') { // runs if 3 key is pressed
		std::cout << "Clicked button 3" << std::endl;
		displayTweetCount = false;
		tweets.clear();
		tweetDate.clear(); // clears any remaining elements in both vectors before further operation in this if statement

		processData("Politics", "politics"); // the following btn elses' 
											 // content will be mostly the same but with different string values passed in
		countWindowLength = 160;
		displayTweetCount = true;
	}
	else if (key == '4') { // runs if 4 key is pressed
		std::cout << "Clicked button 4" << std::endl;
		displayTweetCount = false;
		tweets.clear();
		tweetDate.clear();

		processData("Paris", "paris");
	}
	else if (key == '5') { // runs if 5 key is pressed
		std::cout << "Clicked button 5" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear();

		processDataSingle("DreamWorks"); // summons processDataSingle function with Dreamworks passed in 
	}
	else if (key == '6') { // runs if 6 key is pressed
		std::cout << "Clicked button 6" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear();

		processDataSingle("Uber");  // summons processDataSingle function with Uber  passed in 
	}
	else if (key == '7') { // runs if 7 key is pressed
		std::cout << "Clicked button 7" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear();

		processDataSingle("Trump"); 
		displayTweetCount = true; // sets displayTweetCount to true
		countWindowLength = 170; // sets countWindowLength to 170
	}
	else if (key == '8') { // runs if 8 key is pressed
		std::cout << "Clicked button 8" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear();

		processData("pizza", "Pizza");
		displayTweetCount = true; // sets displayTweetCount to true
		countWindowLength = 150; // sets countWindowLength to 150
	}
	else if (key == '9') { // runs if 9 key is pressed
		std::cout << "Clicked button 9" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear();

		processData("Tokyo", "tokyo");

	}
	else if (key == '0') { // runs if 0 key is pressed
		std::cout << "Clicked button 0" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear();

		processData("America", "america");
	}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

	if (btn1.inside(x, y)) { // runs if btn2 is in the cursor when pressed
		displayTweetCount = false; // returns displayTweetCount to false, removing any previous displayed count of tweets
		tweets.clear();
		tweetDate.clear(); // clears any remaining elements in both vectors before further operation in this if statement
		std::cout << "Clicked button 1" << std::endl; // displays appropriate message to console
		

		for (int b = 0; b < 1550; b++) { // for loop that runs as long as b is less than the 1550, ergo it displays the first 1550 columns

			tweets.push_back(processTweet2[b]);
			tweetDate.push_back(processTweet1[b]); // pushes the values of processTweet1 and processTweet2 into tweets and tweetDate vectors

		}
		
		tweetCount = 63694; // sets tweetCount to 63694 (the number of data lines in the csv) as passing and displaying every single row in the csv file will crash the app
		countWindowLength = 190; // sets countWindowLength to 190
		displayTweetCount = true; // resets displayTweetCount to true to make it count its own number of tweets

		int tweetNum = 0;
		for (int a = 0; a < processTweet2.size(); a++) { // for loop that runs as long as a is less than the size of processTweet2, displaying all the tweets
			tweetNum++;
			//std::cout << processTweet1[a] << " " << processTweet2[a] << std::endl;
		}
		std::cout << "The total amount of tweets in sampleTweets.csv is " << tweetNum << std::endl; // displays every tweet in the csv file to console using cout 
	}
	else if (btn2.inside(x, y)) { // runs if btn2 is in the cursor when pressed
		std::cout << "Clicked button 2" << std::endl; // displays appropriate message to console
		displayTweetCount = false; 
		tweets.clear();
		tweetDate.clear(); 

		processData("money", "Money"); // summons processData function with "money" and "Money" passed in as parameter
		countWindowLength = 160;
		displayTweetCount = true;
	}
	else if (btn3.inside(x, y)) { // runs if btn3 is in the cursor when pressed
		std::cout << "Clicked button 3" << std::endl;
		displayTweetCount = false;
		tweets.clear();
		tweetDate.clear(); // clears any remaining elements in both vectors before further operation in this if statement

		processData("Politics", "politics"); // the following btn elses' 
		                                     // content will be mostly the same but with different string values passed in
		countWindowLength = 160;
		displayTweetCount = true; 
	}
	else if (btn4.inside(x, y)) { // runs if btn4 is in the cursor when pressed
		std::cout << "Clicked button 4" << std::endl; 
		displayTweetCount = false;
		tweets.clear();
		tweetDate.clear(); 

		processData("Paris", "paris");
	}
	else if (btn5.inside(x, y)) { // runs if btn5 is in the cursor when pressed
		std::cout << "Clicked button 5" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processDataSingle("DreamWorks"); // summons processDataSingle function with Dreamworks passed in 
	}
	else if (btn6.inside(x, y)) { // runs if btn6 is in the cursor when pressed
		std::cout << "Clicked button 6" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processDataSingle("Uber");  // summons processDataSingle function with Uber  passed in 
	}
	else if (btn7.inside(x, y)) { // runs if btn7 is in the cursor when pressed
		std::cout << "Clicked button 7" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processDataSingle("Trump");
		displayTweetCount = true; // sets displayTweetCount to true
		countWindowLength = 170; // sets countWindowLength to 170
	}
	else if (btn8.inside(x, y)) { // runs if btn8 is in the cursor when pressed
		std::cout << "Clicked button 8" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processData("pizza", "Pizza");
		displayTweetCount = true; // sets displayTweetCount to true
		countWindowLength = 150; // sets countWindowLength to 150
	}
	else if (btn9.inside(x, y)) { // runs if btn9 is in the cursor when pressed
		std::cout << "Clicked button 9" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processData("Tokyo", "tokyo");
		
	}
	else if (btn10.inside(x, y)) { // runs if btn10 is in the cursor when pressed
		std::cout << "Clicked button 10" << std::endl;
		displayTweetCount = false; // returns displayTweetCount to false
		tweets.clear();
		tweetDate.clear(); 

		processData("America", "america");
	}
}

void ofApp::processData(string srchTerm, string srchTerm2) {

	for (int a = 0; a < processTweet2.size(); a++) { // for loop that runs as long as a is less than the size of tweet2

		string srch = processTweet2[a]; // uses string srch to represent the value of the current element of tweet2
		if (srch.find(srchTerm) != string::npos || srch.find(srchTerm2) != string::npos) { // nested if statement that runs if srchTerm or srchTerm2 has any value equal to the passed in string element 
			tweets.push_back(processTweet2[a]); 
			tweetDate.push_back(processTweet1[a]); // pushes the values of processTweet1 and processTweet2 into tweets and tweetDate vectors
		}

	}
	tweetCount = tweets.size(); // assigns to tweetCount the value of the size of tweets vector

}

//--------------------------------------------------------------
void ofApp::processDataSingle(string srchTerm) {
	
	for (int a = 0; a < processTweet2.size(); a++) { // for loop that runs as long as a is less than the size of tweet2

		string srch = processTweet2[a]; // uses string srch to represent the value of the current element of tweet2
		if (srch.find(srchTerm) != string::npos) { // nested if statement that runs if srchTerm has any value equal to the passed in string element 
			tweets.push_back(processTweet2[a]); 
			tweetDate.push_back(processTweet1[a]); // pushes the values of processTweet1 and processTweet2 into tweets and tweetDate vectors
		}

	}
	tweetCount = tweets.size(); // assigns to tweetCount the value of the size of tweets vector
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

// --------------------------------------------------------------
string ofApp::wrapString(string text, int width) {
	string typeWrapped = "";
	string tempString = "";
	vector <string> words = ofSplitString(text, " "); //create vector full of individual words in string passed in

	for (int i = 0; i < words.size(); i++) { //run through vector
		string wrd = words[i]; //get current word in vector

		// if we aren't on the first word, add a space
		if (i > 0) {
			tempString += " ";
		}
		tempString += wrd; //add current word to temp string

		int stringwidth = medTxt.stringWidth(tempString); //set string width to length of line

		if (stringwidth >= width) {//check string with to add either space or new line before current word
			typeWrapped += "\n"; //if line is now longer than desired width add a new line
			tempString = wrd; // make sure we're including the extra word on the next line
		}
		else if (i > 0) {
			typeWrapped += " "; // if we aren't on the first word, add a space
		}
		typeWrapped += wrd; //add current word to string to be returned with new lines for wrapping
	}

	return typeWrapped;

}