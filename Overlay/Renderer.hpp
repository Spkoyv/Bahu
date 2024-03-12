#pragma once
#include <GL/gl.h>
#include <algorithm>
#include "../Features/Sense.hpp"
#include "../imgui/imgui.h"
#include "../Utils/Color.hpp"
#include "../Utils/Modules.hpp"
#include "../Math/Vector2D.hpp"
#include "../Math/Vector4D.hpp"
#include "../Core/LocalPlayer.hpp"
#include "../Core/Player.hpp"

class Renderer {
public:

    static void DrawText(ImDrawList* canvas, const Vector2D& pos, const char* text, ImColor color, bool outline, bool centered, bool adjustHeight) {
	const auto textColor = color;
        const auto outlineColor = ImColor(0, 0, 0);

        const auto textSize = ImGui::CalcTextSize(text);
        const auto horizontalOffset = centered ? textSize.x / 2 : 0.0f;
        const auto verticalOffset = adjustHeight ? textSize.y : 0.0f;

        if (outline) {
            canvas->AddText({pos.x - horizontalOffset, pos.y - verticalOffset - 1}, outlineColor, text);
            canvas->AddText({pos.x - horizontalOffset, pos.y - verticalOffset + 1}, outlineColor, text);
            canvas->AddText({pos.x - horizontalOffset - 1, pos.y - verticalOffset}, outlineColor, text);
            canvas->AddText({pos.x - horizontalOffset + 1, pos.y - verticalOffset}, outlineColor, text);
        }
        canvas->AddText({pos.x - horizontalOffset, pos.y - verticalOffset}, textColor, text);
	}


    static void DrawCircle(ImDrawList* canvas, const Vector2D& pos, float radius, int segments, const ImColor& color, float thickness) {
		canvas->AddCircle(ImVec2(pos.x, pos.y), radius, color, segments, thickness);
	}

    static void DrawCircleFilled(ImDrawList* canvas, const Vector2D& pos, float radius, int segments, const ImColor& color) {
		canvas->AddCircleFilled(ImVec2(pos.x, pos.y), radius, color, segments);
	}

    static void DrawLine(ImDrawList* canvas, const Vector2D& start, const Vector2D& end, float thickness, const ImColor& color) {
		canvas->AddLine((const ImVec2&)start, (const ImVec2&)end, ImColor(color), thickness);
	}

    static void DrawQuadFilled(ImDrawList* canvas, ImVec2 p1, ImVec2 p2, ImVec2 p3, ImVec2 p4, ImColor color) {
	    canvas->AddQuadFilled(p1, p2, p3, p4, color);
    }

    static void DrawHexagon(ImDrawList* canvas, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col, float thickness) {
        canvas->AddHexagon(p1, p2, p3, p4, p5, p6, col, thickness);
    }

    static void DrawHexagonFilled(ImDrawList* canvas, const ImVec2& p1, const ImVec2& p2, const ImVec2& p3, const ImVec2& p4, const ImVec2& p5, const ImVec2& p6, ImU32 col) {
        canvas->AddHexagonFilled(p1, p2, p3, p4, p5, p6, col);
    }

    //Bar Style 1
    static void drawRectangleOutline(Vector2D position, Vector2D size, Color color, float lineWidth) {

        glLineWidth(lineWidth);
        glColor3f(color.r, color.g, color.b);

        glBegin(GL_LINE_LOOP);
            glVertex2f(position.x, position.y);
            glVertex2f(position.x + size.x, position.y);
            glVertex2f(position.x + size.x, position.y + size.y);
            glVertex2f(position.x, position.y + size.y);
        glEnd();

        glLineWidth(1.0f);
    }
    
    static void drawFilledRectagle(Vector2D position, Vector2D size, Color color) {

        glColor3f(color.r, color.g, color.b);
        glBegin(GL_QUADS);
            glVertex2f(position.x, position.y);
            glVertex2f(position.x + size.x, position.y);
            glVertex2f(position.x + size.x, position.y + size.y);
            glVertex2f(position.x, position.y + size.y);
        glEnd();
    }
    
    static void drawBorderedFillRectangle(Vector2D position, Vector2D size, Color fillColor, Color borderColor, float lineWidth, float fill) {
        drawFilledRectagle(position, Vector2D(size.x, size.y), Color(0, 0, 0));
        drawFilledRectagle(position, Vector2D(size.x * fill, size.y), fillColor);
        drawRectangleOutline(position, size, borderColor, lineWidth);
    }

//Features

//DrawBox
    static void Draw2DBox(ImDrawList* canvas, int Type, int Style, Vector2D& foot, const Vector2D& head, const ImColor& color2D, const ImColor& Filledcolor, float thickness) {
        //Type = 2D, 2D Filled
        //Style = 1 or 2, idk what to call them (for now)
        if (Type == 0) { //2D Box
            if (Style == 0) {
                float height = head.y - foot.y;
    	        float width = height / 2.0f;
    	        canvas->AddRect(ImVec2(foot.x - (width / 2), foot.y), ImVec2(head.x + (width/2), head.y+(height*0.2)), color2D, 0.0f, 0, thickness);
            }
            if (Style == 1) {
                float Height = (head.y - foot.y);
                Vector2D rectTop = Vector2D(head.x - Height / 3, head.y);
                Vector2D rectBottom = Vector2D(foot.x + Height / 3, foot.y);
                canvas->AddRect(ImVec2(rectBottom.x, rectBottom.y), ImVec2(rectTop.x, rectTop.y + (Height*0.2)), color2D, 0.0f, 0, thickness);
            }
        }
        if (Type == 1) { //2D Box + 2D Filled Box
            float height = head.y - foot.y;
            float width = height / 2.0f;
            float x = foot.x - (width / 2.f);
	 
            Renderer::DrawCorneredBox(canvas, x, foot.y, width, height, color2D, thickness);
        }
    }

//Draw 2D Bars
    static void Draw2DBar(ImDrawList* canvas, int BarMode, int BarStyle, int ColorMode, bool Background, Vector2D& Foot, Vector2D& Head, int health, int maxHealth, int shield, int maxShield, float thickness, float thickness2, float BarWidth, float BarHeight, const ImColor& BGColor) {
        //Pre-Stuff
        if (Background) { //Background
            if (BarStyle == 0) { //Side Bar Background
                float entityHeight = Foot.y - Head.y;
                float boxLeft = Foot.x - entityHeight / 3;
                float boxRight = Head.x + entityHeight / 3;
                float barPercentWidth = thickness2;
                float barPixelWidth = barPercentWidth * (boxRight - boxLeft);
                float barHeight = entityHeight;
                Vector2D barTopBG = Vector2D(boxLeft - barPixelWidth, Foot.y - barHeight);
                Vector2D barBottomBG = Vector2D(boxLeft, Foot.y);
                canvas->AddRectFilled(ImVec2(barTopBG.x, barTopBG.y - (entityHeight * 0.2)), ImVec2(barBottomBG.x, barBottomBG.y), BGColor);
            }
        }
        //Shield Color
        ImColor shieldBarColor;
        if (ColorMode == 0) {//MaxShield
			if (maxShield == 50) { //white
				shieldBarColor = ImColor(168, 168, 168, 255);
			}
			else if (maxShield == 75) { //blue
				shieldBarColor = ImColor(39, 178, 255, 255);
			}
			else if (maxShield == 100) { //purple
				shieldBarColor = ImColor(206, 59, 255, 255);
			}
			else if (maxShield == 125) { //red
				shieldBarColor = ImColor(219, 2, 2, 255);
			}
        }

        if (ColorMode == 1) {//Current Shield
			if (shield <= 50) { //white
				shieldBarColor = ImColor(168, 168, 168, 255);
			}
			else if (shield <= 75) { //blue
				shieldBarColor = ImColor(39, 178, 255, 255);
			}
			else if (shield <= 100) { //purple
				shieldBarColor = ImColor(206, 59, 255, 255);
			}
			else if (shield <= 125) { //red
				shieldBarColor = ImColor(219, 2, 2, 255);
			}
        }

        //Bars
        if (BarMode == 0) { //Health Only
            if (BarStyle == 0) {//Side Bar
                //New Bar
                float entityHeight = Foot.y - Head.y;
                float boxLeft = Foot.x - entityHeight / 3;
                float boxRight = Head.x + entityHeight / 3;
                float barPercentWidth = thickness2;
                float barPixelWidth = barPercentWidth * (boxRight - boxLeft);
                float barHeight = entityHeight * (health / 100.0f);
                Vector2D barTop = Vector2D(boxLeft - barPixelWidth, Foot.y - barHeight);
                Vector2D barBottom = Vector2D(boxLeft, Foot.y);

                canvas->AddRectFilled(ImVec2(barTop.x, barTop.y - (entityHeight * 0.2)), ImVec2(barBottom.x, barBottom.y), ImColor(0, 255, 0));
            }
            if (BarStyle == 1) {//Top Bar
                float height = BarHeight; //8.0f
                float width = BarWidth; //80.0f
                Vector2D rectPosition = Vector2D(Foot.x - width/2, Head.y - 10.0f);
                Vector2D size = Vector2D(width, height);
                
                //HealthBar
                float fill = (float)health/(float)maxHealth;
                Renderer::drawBorderedFillRectangle(rectPosition, size, Color::lerp(Color(1.0, 0.0, 0.0), Color(0.0, 1.0, 0.0), fill), Color(), thickness, fill);
            }

        }
        if (BarMode == 1) { //Shield Only
            if (BarStyle == 0) {//Side Bar
                //New Bar
                float entityHeight = Foot.y - Head.y;
                float boxLeft = Foot.x - entityHeight / 3;
                float boxRight = Head.x + entityHeight / 3;
                float barPercentWidth = thickness2;
                float barPixelWidth = barPercentWidth * (boxRight - boxLeft);
                float maxS; //maxShield
                float s = shield; //shield

                if (s == 0) {
                shieldBarColor = ImColor(0, 0, 0, 0);
                }

                float barHeight = entityHeight * (s / maxS);
                Vector2D barTop = Vector2D(boxLeft - barPixelWidth, Foot.y - barHeight);
                Vector2D barBottom = Vector2D(boxLeft, Foot.y);

                canvas->AddRectFilled(ImVec2(barTop.x, barTop.y - (entityHeight * 0.2)), ImVec2(barBottom.x, barBottom.y), ImColor(shieldBarColor));
            }
            if (BarStyle == 1) {//Top Bar
                float height = BarHeight; //8.0f
                float width = BarWidth; //80.0f
                Vector2D rectPosition = Vector2D(Foot.x - width/2, Head.y - 10.0f);
                Vector2D size = Vector2D(width, height);
                
                //ShieldBar
                float fill = (float)shield/(float)maxShield;
                if (maxShield == 125) { //Red Shield
                    Renderer::drawBorderedFillRectangle(Vector2D(rectPosition.x, rectPosition.y - (height + 3)), size, Color::lerp(Color(1.0, 0.0, 0.0), Color(1.0, 0.0, 0.0), fill), Color(), thickness, fill);
                }
                if (maxShield == 100) { //Purple Shield
                    Renderer::drawBorderedFillRectangle(Vector2D(rectPosition.x, rectPosition.y - (height + 3)), size, Color::lerp(Color(0.501, 0.00, 0.970), Color(0.501, 0.00, 0.970), fill), Color(), thickness, fill);
                }
                if (maxShield == 75) { //Blue Shield
                    Renderer::drawBorderedFillRectangle(Vector2D(rectPosition.x, rectPosition.y - (height + 3)), size, Color::lerp(Color(0.0297, 0.734, 0.990), Color(0.0297, 0.734, 0.990), fill), Color(), thickness, fill);
                }
                if (maxShield == 50) { //Grey Shield
                    Renderer::drawBorderedFillRectangle(Vector2D(rectPosition.x, rectPosition.y - (height + 3)), size, Color::lerp(Color(0.707, 0.702, 0.700), Color(0.707, 0.702, 0.700), fill), Color(), thickness, fill);
                }
            }
        }

        if (BarMode == 2) { //Health & Shield
            if (BarStyle == 0) {//Side Bar
                //HP Bar
                float entityHeight = Foot.y - Head.y;
                float boxLeft = Foot.x - entityHeight / 3;
                float boxRight = Head.x + entityHeight / 3;
                float barPercentWidth = thickness2;
                float barPixelWidth = barPercentWidth * (boxRight - boxLeft);
                float barHeight = entityHeight * (health / 100.0f);
                Vector2D barTop = Vector2D(boxLeft - barPixelWidth, Foot.y - barHeight);
                Vector2D barBottom = Vector2D(boxLeft, Foot.y);

                canvas->AddRectFilled(ImVec2(barTop.x, barTop.y - (entityHeight * 0.2)), ImVec2(barBottom.x, barBottom.y), ImColor(0, 255, 0));
            
                //Shield Bar
                float maxS; //maxShield
                float s = shield; //shield
                if (maxShield == 125) {
                    maxS = 125.0f;
                }
                else if (maxShield == 100) {
                    maxS = 100.0f;
                }
                else if (maxShield == 75) {
                    maxS = 75.0f;
                }
                else if (maxShield == 50) {
                    maxS = 50.0f;
                }

                if (s == 0) {
                    shieldBarColor = ImColor(0, 0, 0, 0);
                }

                float barHeightAP = entityHeight * (s / maxS);
                Vector2D barTopAP = Vector2D(boxLeft - barPixelWidth, Foot.y - barHeightAP);
                Vector2D barBottomAP = Vector2D(boxLeft, Foot.y);

                canvas->AddRectFilled(ImVec2(barTopAP.x, barTopAP.y - (entityHeight * 0.2)), ImVec2(barBottomAP.x, barBottomAP.y), ImColor(shieldBarColor));
            }

            if (BarStyle == 1) {//Top Bar
                float height = BarHeight; //8.0f
                float width = BarWidth; //80.0f
                Vector2D rectPosition = Vector2D(Foot.x - width/2, Head.y - 10.0f);
                Vector2D size = Vector2D(width, height);
                
                //HealthBar
                float fillHP = (float)health/(float)maxHealth;
                Renderer::drawBorderedFillRectangle(rectPosition, size, Color::lerp(Color(1.0, 0.0, 0.0), Color(0.0, 1.0, 0.0), fillHP), Color(), thickness, fillHP);
                
                //ShieldBar
                float fillAP = (float)shield/(float)maxShield;
                if (maxShield == 125) { //Red Shield
                    Renderer::drawBorderedFillRectangle(Vector2D(rectPosition.x, rectPosition.y - (height + 3)), size, Color::lerp(Color(1.0, 0.0, 0.0), Color(1.0, 0.0, 0.0), fillAP), Color(), thickness, fillAP);
                }
                if (maxShield == 100) { //Purple Shield
                    Renderer::drawBorderedFillRectangle(Vector2D(rectPosition.x, rectPosition.y - (height + 3)), size, Color::lerp(Color(0.501, 0.00, 0.970), Color(0.501, 0.00, 0.970), fillAP), Color(), thickness, fillAP);
                }
                if (maxShield == 75) { //Blue Shield
                    Renderer::drawBorderedFillRectangle(Vector2D(rectPosition.x, rectPosition.y - (height + 3)), size, Color::lerp(Color(0.0297, 0.734, 0.990), Color(0.0297, 0.734, 0.990), fillAP), Color(), thickness, fillAP);
                }
                if (maxShield == 50) { //Grey Shield
                    Renderer::drawBorderedFillRectangle(Vector2D(rectPosition.x, rectPosition.y - (height + 3)), size, Color::lerp(Color(0.707, 0.702, 0.700), Color(0.707, 0.702, 0.700), fillAP), Color(), thickness, fillAP);
                }
            }
        }
    }


static void DrawRectFilled(ImDrawList* canvas, float x, float y, float x2, float y2, ImColor color, float rounding, int rounding_corners_flags) {
	    canvas->AddRectFilled(ImVec2(x, y), ImVec2(x2, y2), color, rounding, rounding_corners_flags);
    }
    
    static void DrawProgressBar(ImDrawList* canvas, float x, float y, float w, float h, int value, int v_max, ImColor barColor)
   {


	DrawRectFilled(canvas, x, y, x + w, y - ((h / float(v_max)) * (float)value), barColor, 0.0f, 0);
	
        canvas->AddRect(ImVec2(x-1, y - 1), ImVec2(x + w +1, y - h+1), ImColor(0, 0, 0), 0, 1);
   }
   
    static void DrawCorneredBox(ImDrawList* canvas,  float X, float Y, float W, float H, ImColor color, float thickness) {
		float lineW = (W / 4);
		float lineH = (H / 5.5);
		float lineT = -thickness;


	//corners
	DrawLine(canvas,Vector2D(X, Y +thickness/2), Vector2D(X, Y + lineH), thickness, color);//bot right vert
	DrawLine(canvas,Vector2D(X +thickness/2, Y), Vector2D(X + lineW, Y), thickness, color);
 
	DrawLine(canvas,Vector2D(X + W - lineW, Y), Vector2D(X + W -thickness / 2, Y), thickness, color);//bot left hor
	DrawLine(canvas,Vector2D(X + W, Y +thickness/2), Vector2D(X + W, Y + lineH), thickness, color);

	DrawLine(canvas,Vector2D(X, Y + H - lineH), Vector2D(X, Y + H-(thickness/2)), thickness, color);//top right vert
    DrawLine(canvas,Vector2D(X +thickness/2, Y + H), Vector2D(X + lineW, Y + H), thickness, color);

	DrawLine(canvas,Vector2D(X + W - lineW, Y + H), Vector2D(X + W-thickness/2, Y + H), thickness, color);//top left hor
	DrawLine(canvas,Vector2D(X + W, Y + H - lineH), Vector2D(X + W, Y + H - (thickness/ 2)), thickness, color);

	//black outlines   
    ImColor Black = ImColor(0, 0, 0);
        
	DrawLine(canvas,Vector2D(X - lineT, Y - lineT +thickness/2), Vector2D(X - lineT, Y + lineH), thickness , Black); //bot right vert
    DrawLine(canvas,Vector2D(X - lineT +thickness/2, Y - lineT), Vector2D(X + lineW, Y - lineT), thickness , Black);
        
	DrawLine(canvas,Vector2D(X + W - lineW, Y - lineT), Vector2D(X + W - (thickness/ 2) + lineT, Y - lineT), thickness , Black); //bot left hor
	DrawLine(canvas,Vector2D(X + W + lineT, Y - lineT +thickness/2), Vector2D(X + W + lineT, Y + lineH), thickness , Black);
	
    DrawLine(canvas,Vector2D(X - lineT, Y + H - lineH), Vector2D(X - lineT, Y + H -(thickness/2) + lineT ), thickness , Black); //top right vert
	DrawLine(canvas,Vector2D(X +thickness/2 - lineT, Y + H + lineT), Vector2D(X + lineW, Y + H + lineT), thickness , Black); //top right hor
	
	DrawLine(canvas,Vector2D(X + W - lineW, Y + H + lineT), Vector2D(X + W - (thickness/ 2) + lineT , Y + H + lineT), thickness , Black); //top left hor
	DrawLine(canvas,Vector2D(X + W + lineT, Y + H - lineH), Vector2D(X + W + lineT, Y + H + lineT - (thickness/ 2)), thickness , Black);
          
        
        
        
}


    static void DrawSeer(ImDrawList* Canvas, float x, float y, int shield, int max_shield, int health) {
        int bg_offset = 3;
        int bar_width = 158;
        float max_health = 100.0f;
        float shield_step = 25.0f;
        ImVec2 bg1(x - bar_width / 2 - bg_offset, y);
        ImVec2 bg2(bg1.x - 10, bg1.y - 16);
        ImVec2 bg3(bg2.x + 5, bg2.y - 7);
        ImVec2 bg4(bg3.x + bar_width + bg_offset, bg3.y);
        ImVec2 bg5(bg4.x + 11, bg4.y + 18);
        ImVec2 bg6(x + bar_width / 2 + bg_offset, y);
        Renderer::DrawHexagonFilled(Canvas, bg1, bg2, bg3, bg4, bg5, bg6, ImColor(0, 0, 0, 120));

        ImVec2 h1(bg1.x + 3, bg1.y - 4);
        ImVec2 h2(h1.x - 5, h1.y - 8);
        ImVec2 h3(h2.x + (float)health / max_health * bar_width, h2.y);
        ImVec2 h4(h1.x + (float)health / max_health * bar_width, h1.y);
        ImVec2 h3m(h2.x + bar_width, h2.y);
        ImVec2 h4m(h1.x + bar_width, h1.y);
        Renderer::DrawQuadFilled(Canvas, h1, h2, h3m, h4m, ImColor(10,10,30,60));
        Renderer::DrawQuadFilled(Canvas, h1, h2, h3, h4, ImColor(255, 255, 255, 255));
    
        //Shield
        ImColor shieldCracked(97,97,97);
        ImColor shieldCrackedDark(67, 67, 67);

        ImColor shieldCol;
        ImColor shieldColDark;
        if (max_shield == 50) { //white
            shieldCol = ImColor(247, 247, 247);
            shieldColDark = ImColor(164, 164, 164);
        }
        else if (max_shield == 75) { //blue
            shieldCol = ImColor(39, 178, 255);
            shieldColDark = ImColor(27, 120, 210);
        }
        else if (max_shield == 100) { //purple
            shieldCol = ImColor(206, 59, 255);
            shieldColDark = ImColor(136, 36, 220);
        }
        else if (max_shield == 125) { //red
            shieldCol = ImColor(219, 2, 2);
            shieldColDark = ImColor(219, 2, 2);
        }
        else {
            shieldCol = ImColor(247, 247, 247);
            shieldColDark = ImColor(164, 164, 164);
        }

        int shield_25 = 30;
        int shield_tmp = shield;
        int shield1 =0;
        int shield2 =0;
        int shield3 =0;
        int shield4 =0;
        int shield5 =0;
        if (shield_tmp > 25) {
            shield1 = 25;
            shield_tmp -= 25;
            if (shield_tmp > 25) {
                shield2 = 25;
                shield_tmp -= 25;
                if (shield_tmp > 25) {
                    shield3 = 25;
                    shield_tmp -= 25;
                    if (shield_tmp > 25) {
                        shield4 = 25;
                        shield_tmp -= 25;
                        shield5 = shield_tmp;
                    }
                    else {
                        shield4 = shield_tmp;
                    }
                }
                else {
                    shield3 = shield_tmp;
                }
            }
            else {
                shield2 = shield_tmp;
            }
        }
        else {
            shield1 = shield_tmp;
        }

        ImVec2 s1(h2.x - 1, h2.y - 2);
        ImVec2 s2(s1.x - 3, s1.y - 5);
        ImVec2 s3(s2.x + shield1 / shield_step * shield_25, s2.y);
        ImVec2 s4(s1.x + shield1 / shield_step * shield_25, s1.y);
        ImVec2 s3m(s2.x + shield_25, s2.y);
        ImVec2 s4m(s1.x + shield_25, s1.y);
    
        ImVec2 ss1(s4m.x + 2, s1.y);
        ImVec2 ss2(s3m.x + 2, s2.y);
        ImVec2 ss3(ss2.x + shield2 / shield_step * shield_25, s2.y);
        ImVec2 ss4(ss1.x + shield2 / shield_step * shield_25, s1.y);
        ImVec2 ss3m(ss2.x + shield_25, s2.y);
        ImVec2 ss4m(ss1.x + shield_25, s1.y);
        
        ImVec2 sss1(ss4m.x + 2, s1.y);
        ImVec2 sss2(ss3m.x + 2, s2.y);
        ImVec2 sss3(sss2.x + shield3 / shield_step * shield_25, s2.y);
        ImVec2 sss4(sss1.x + shield3 / shield_step * shield_25, s1.y);
        ImVec2 sss3m(sss2.x + shield_25, s2.y);
        ImVec2 sss4m(sss1.x + shield_25, s1.y);
        
        ImVec2 ssss1(sss4m.x + 2, s1.y);
        ImVec2 ssss2(sss3m.x + 2, s2.y);
        ImVec2 ssss3(ssss2.x + shield4 / shield_step * shield_25, s2.y);
        ImVec2 ssss4(ssss1.x + shield4 / shield_step * shield_25, s1.y);
        ImVec2 ssss3m(ssss2.x + shield_25, s2.y);
        ImVec2 ssss4m(ssss1.x + shield_25, s1.y);
        
        ImVec2 sssss1(ssss4m.x + 2, s1.y);
        ImVec2 sssss2(ssss3m.x + 2, s2.y);
        ImVec2 sssss3(sssss2.x + shield5 / shield_step * shield_25, s2.y);
        ImVec2 sssss4(sssss1.x + shield5 / shield_step * shield_25, s1.y);
        ImVec2 sssss3m(sssss2.x + shield_25, s2.y);
        ImVec2 sssss4m(sssss1.x + shield_25, s1.y);
        if (max_shield == 50) {
            if (shield <= 25) {
                if (shield < 25) {
                    Renderer::DrawQuadFilled(Canvas, s1, s2, s3m, s4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3m, ss4m, shieldCracked);
                }
                if(shield != 0)
                    Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
    
            }
            else if (shield <= 50) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                if (shield != 50) {
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3m, ss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
            }
        }
        else if (max_shield == 75) {
            if (shield <= 25) {
                if (shield < 25) {
                    Renderer::DrawQuadFilled(Canvas, s1, s2, s3m, s4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3m, ss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3m, sss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
    
            }
            else if (shield <= 50) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                if (shield < 50) {
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3m, ss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3m, sss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
            }
            else if (shield <= 75) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
                if (shield < 75) {
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3m, sss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3, sss4, shieldCol);
            }
        }
        else if (max_shield == 100) {
            if (shield <= 25) {
                if (shield < 25) {
                    Renderer::DrawQuadFilled(Canvas, s1, s2, s3m, s4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3m, ss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3m, sss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
    
            }
            else if (shield <= 50) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                if (shield < 50) {
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3m, ss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3m, sss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
            }
            else if (shield <= 75) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
                if (shield < 75) {
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3m, sss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3, sss4, shieldCol);
            }
            else if (shield <= 100) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3, sss4, shieldCol);
                if (shield < 100) {
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3, ssss4, shieldCol);
            }
        }
        else if (max_shield == 125) {
            if (shield <= 25) {
                if (shield < 25) {
                    Renderer::DrawQuadFilled(Canvas, s1, s2, s3m, s4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3m, ss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3m, sss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
    
            }
            else if (shield <= 50) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                if (shield < 50) {
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3m, ss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3m, sss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
            }
            else if (shield <= 75) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
                if (shield < 75) {
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3m, sss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3, sss4, shieldCol);
            }
            else if (shield <= 100) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3, sss4, shieldCol);
                if (shield < 100) {
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3m, ssss4m, shieldCracked);
                    Renderer::DrawQuadFilled(Canvas, sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3, ssss4, shieldCol);
            }
            else if (shield <= 125) {
                Renderer::DrawQuadFilled(Canvas, s1, s2, s3, s4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, ss1, ss2, ss3, ss4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, sss1, sss2, sss3, sss4, shieldCol);
                Renderer::DrawQuadFilled(Canvas, ssss1, ssss2, ssss3, ssss4, shieldCol);
                if (shield < 125) {
                    Renderer::DrawQuadFilled(Canvas, sssss1, sssss2, sssss3m, sssss4m, shieldCracked);
                }
                if (shield != 0)
                    Renderer::DrawQuadFilled(Canvas, sssss1, sssss2, sssss3, sssss4, shieldCol);
            }
        }
    }
    
    static Vector3D RotatePoint(Vector3D EntityPos, Vector3D LocalPlayerPos, int posX, int posY, int sizeX, int sizeY, float angle, float zoom, bool* viewCheck) {
    	float r_1, r_2;
    	float x_1, y_1;
     
    	r_1 = -(EntityPos.y - LocalPlayerPos.y);
    	r_2 = EntityPos.x - LocalPlayerPos.x;
    	
    	float yawToRadian = angle * (float)(M_PI / 180.0F);
    	x_1 = (float)(r_2 * (float)cos((double)(yawToRadian)) - r_1 * sin((double)(yawToRadian))) / 20;
    	y_1 = (float)(r_2 * (float)sin((double)(yawToRadian)) + r_1 * cos((double)(yawToRadian))) / 20;
     
    	*viewCheck = y_1 < 0;
     
    	x_1 *= zoom;
    	y_1 *= zoom;
     
    	int sizX = sizeX / 2;
    	int sizY = sizeY / 2;
     
    	x_1 += sizX;
    	y_1 += sizY;
     
    	if (x_1 < 5)
    		x_1 = 5;
     
    	if (x_1 > sizeX - 5)
    		x_1 = sizeX - 5;
     
    	if (y_1 < 5)
    		y_1 = 5;
     
    	if (y_1 > sizeY - 5)
    		y_1 = sizeY - 5;
     
     
    	x_1 += posX;
    	y_1 += posY;
     
     
    	return Vector3D(x_1, y_1, 0);
    }
    
    static void TeamMiniMap(int x, int y, int radius, int teamID, float targetyaw, int dotSize, int outlineSize, int aimlinelength, const ImColor& circleColor) {
        auto colOutline = ImGui::ColorConvertFloat4ToU32(ImVec4(255, 255, 255, 1.0));
        ImVec2 center(x, y);
        //ImGui::GetWindowDrawList()->AddCircleFilled(center, radius, ImGui::ColorConvertFloat4ToU32(ImVec4(0.99, 0, 0, 0.99)));
        //ImGui::GetWindowDrawList()->AddCircle(center, radius, colOutline, 12, radius);
        ImGui::GetWindowDrawList()->AddCircleFilled(center, radius, circleColor);
        ImGui::GetWindowDrawList()->AddCircle(center, outlineSize, colOutline, 12, radius);

        // Draw a line pointing in the direction of each player's aim
        const int numPlayers = 3;
        for (int i = 0; i < numPlayers; i++) {
            float angle = (360.0 - targetyaw) * (M_PI / 180.0); // Replace this with the actual yaw of the player, then convert it to radians.
            ImVec2 endpoint(center.x + aimlinelength * cos(angle), center.y + aimlinelength * sin(angle));
            ImGui::GetWindowDrawList()->AddLine(center, endpoint, colOutline, 1.f);
        }
    }
};
