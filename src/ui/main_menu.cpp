#include "../../include/ui/main_menu.h"

MainMenu::MainMenu(std::string startBtnText, std::string settingsBtnText, std::string quitBtnText){
	this->startBtnText = startBtnText;
	this->settingsBtnText = settingsBtnText;
	this->quitBtnText = quitBtnText;	
}

//Setters

void MainMenu::startButton(){
	//to do
}
	
void MainMenu::setStartButtonText(std::string label){
	this->startBtnText = label;
}

void MainMenu::setStartButtonWidth(size_t width){
	this->startBtnWidth = width;
}

void MainMenu::setStartButtonHeight(size_t height){
	this->startBtnHeight = height;
}

void MainMenu::setStartButtonBorderRadius(float radius){
	this->startBtnRadius = radius;
}

void MainMenu::setStartButtonBackgroundColor(float r, float g, float b, float a){
	//to do
}


void MainMenu::settingsButton(){
	//to do
}

void MainMenu::setSettingsButtonText(std::string label){
	this->settingsBtnText = label;
}

void MainMenu::setSettingsButtonWidth(size_t width){
	this->settingsBtnWidth = width;
}

void MainMenu::setSettingsButtonHeight(size_t height){
	this->settingsBtnHeight = height;
}

void MainMenu::setSettingsButtonBorderRadius(float radius){
	this->settingsBtnRadius = radius;
}

void MainMenu::setSettingsButtonBackgroundColor(float r, float g, float b, float a){
	//to do
}


void MainMenu::quitButton(){
	//to do
}

void MainMenu::setQuitButtonText(std::string label){
	this->quitBtnText = label;
}

void MainMenu::setQuitButtonWidth(size_t width){
	this->quitBtnWidth = width;
}

void MainMenu::setQuitButtonHeight(size_t height){
	this->quitBtnHeight = height;
}

void MainMenu::setQuitButtonBorderRadius(float radius){
	this->quitBtnRadius = radius;
}

void MainMenu::setQuitButtonBackgroundColor(float r, float g, float b, float a){
	//to do
}

void MainMenu::setPosX(size_t posX){
	this->posX = posX;
}

void MainMenu::setPosY(size_t posY){
	this->posY = posY;
}

void MainMenu::setWidth(size_t width){
	this->width = width;
}

void MainMenu::setHeight(size_t height){
	this->height = height;
}

//Getters

std::string MainMenu::getStartButtonText(){
	return this->startBtnText;
}

size_t MainMenu::getStartButtonWidth(){
	return this->startBtnWidth;
}

size_t MainMenu::getStartButtonHeight(){
	return this->startBtnHeight;
}

float MainMenu::getStartButtonBorderRadius(){
	return this->startBtnRadius;
}

float MainMenu::getStartButtonBackgroundColor(){
	//to do
	return 0.0;
}

std::string MainMenu::getSettingsButtonText(){
	return this->settingsBtnText;
}

size_t MainMenu::getSettingsButtonWidth(){
	return this->settingsBtnWidth;
}

size_t MainMenu::getSettingsButtonHeight(){
	return this->settingsBtnHeight;
}

float MainMenu::getSettingsButtonBorderRadius(){
	return this->settingsBtnRadius;
}

float MainMenu::getSettingsButtonBackgroundColor(){
	//to do
	return 0.0;
}

std::string MainMenu::getQuitButtonText(){
	return this->quitBtnText;
}

size_t MainMenu::getQuitButtonWidth(){
	return this->quitBtnWidth;
}

size_t MainMenu::getQuitButtonHeight(){
	return this->quitBtnHeight;
}

float MainMenu::getQuitButtonBorderRadius(){
	return this->quitBtnRadius;
}

float MainMenu::getQuitButtonBackgroundColor(){
	//to do
	return 0.0;
}

size_t MainMenu::getPosX(){
	return this->posX;
}

size_t MainMenu::getPosY(){
	return this->posY;
}

size_t MainMenu::getWidth(){
	return this->width;
}

size_t MainMenu::getHeight(){
	return this->height;
}
