#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "IniReader.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

namespace Themes {
    namespace ThemeOptions {
        namespace Styles {
	    	float Alpha = 0.85f;
	    	float DisabledAlpha = 1.0f;
	    	ImVec2 WindowPadding = ImVec2(12.0f, 12.0f);
	    	float WindowRounding = 0.0f;
	    	float WindowBorderSize = 0.0f;
	    	ImVec2 WindowMinSize = ImVec2(20.0f, 20.0f);
	    	ImVec2 WindowTitleAlign = ImVec2(0.5f, 0.5f);
	    	float ChildRounding = 0.0f;
	    	float ChildBorderSize = 1.0f;
	    	float PopupRounding = 0.0f;
	    	float PopupBorderSize = 1.0f;
	    	ImVec2 FramePadding = ImVec2(6.0f, 6.0f);
	    	float FrameRounding = 0.0f;
	    	float FrameBorderSize = 0.0f;
	    	ImVec2 ItemSpacing = ImVec2(12.0f, 6.0f);
	    	ImVec2 ItemInnerSpacing = ImVec2(6.0f, 3.0f);
	    	float LogSliderDeadzone;
	    	ImVec2 TouchExtraPadding;
	    	ImVec2 CellPadding = ImVec2(12.0f, 6.0f);
	    	float IndentSpacing = 20.0f;
	    	float ColumnsMinSpacing = 6.0f;
	    	float ScrollbarSize = 12.0f;
	    	float ScrollbarRounding = 0.0f;
	    	float GrabMinSize = 12.0f;
	    	float GrabRounding = 0.0f;
	    	float TabRounding = 0.0f;
	    	float TabBorderSize = 0.0f;
	    	float TabMinWidthForCloseButton = 0.0f;
	    	ImVec2 ButtonTextAlign = ImVec2(0.5f, 0.5f);
	    	ImVec2 SelectableTextAlign = ImVec2(0.0f, 0.0f);
    	};
    	
    	namespace Colors {
    		ImVec4 Text = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 TextDisabled = ImVec4(0.2745098173618317f, 0.3176470696926117f, 0.4509803950786591f, 1.0f);
		ImVec4 WindowBg = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 ChildBg = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 PopupBg = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 Border = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
		ImVec4 BorderShadow = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 FrameBg = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 FrameBgHovered = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
		ImVec4 FrameBgActive = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 TitleBg = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TitleBgActive = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TitleBgCollapsed = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 MenuBarBg = ImVec4(0.09803921729326248f, 0.105882354080677f, 0.1215686276555061f, 1.0f);
		ImVec4 ScrollbarBg = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 ScrollbarGrab = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 ScrollbarGrabHovered = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
		ImVec4 ScrollbarGrabActive = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 CheckMark = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 SliderGrab = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 SliderGrabActive = ImVec4(0.5372549295425415f, 0.5529412031173706f, 1.0f, 1.0f);
		ImVec4 Button = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 ButtonHovered = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 1.0f);
		ImVec4 ButtonActive = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 Header = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 HeaderHovered = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 1.0f);
		ImVec4 HeaderActive = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 Separator = ImVec4(0.1568627506494522f, 0.1843137294054031f, 0.250980406999588f, 1.0f);
		ImVec4 SeparatorHovered = ImVec4(0.1568627506494522f, 0.1843137294054031f, 0.250980406999588f, 1.0f);
		ImVec4 SeparatorActive = ImVec4(0.1568627506494522f, 0.1843137294054031f, 0.250980406999588f, 1.0f);
		ImVec4 ResizeGrip = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 ResizeGripHovered = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 1.0f);
		ImVec4 ResizeGripActive = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 Tab = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TabHovered = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 TabActive = ImVec4(0.09803921729326248f, 0.105882354080677f, 0.1215686276555061f, 1.0f);
		ImVec4 TabUnfocused = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TabUnfocusedActive = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 PlotLines = ImVec4(0.5215686559677124f, 0.6000000238418579f, 0.7019608020782471f, 1.0f);
		ImVec4 PlotLinesHovered = ImVec4(0.03921568766236305f, 0.9803921580314636f, 0.9803921580314636f, 1.0f);
		ImVec4 PlotHistogram = ImVec4(1.0f, 0.2901960909366608f, 0.5960784554481506f, 1.0f);
		ImVec4 PlotHistogramHovered = ImVec4(0.9960784316062927f, 0.4745098054409027f, 0.6980392336845398f, 1.0f);
		ImVec4 TableHeaderBg = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TableBorderStrong = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TableBorderLight = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
		ImVec4 TableRowBg = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 TableRowBgAlt = ImVec4(0.09803921729326248f, 0.105882354080677f, 0.1215686276555061f, 1.0f);
		ImVec4 TextSelectedBg = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 DragDropTarget = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 NavHighlight = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 NavWindowingHighlight = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 NavWindowingDimBg = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 0.501960813999176f);
		ImVec4 ModalWindowDimBg = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 0.501960813999176f);
	};
    };

//Themes
    namespace ThemeStyles {
    	namespace Original {
    	    namespace Styles {
	    	float Alpha = 0.85f;
		float DisabledAlpha = 1.0f;
		ImVec2 WindowPadding = ImVec2(12.0f, 12.0f);
		float WindowRounding = 0.0f;
		float WindowBorderSize = 0.0f;
		ImVec2 WindowMinSize = ImVec2(20.0f, 20.0f);
		ImVec2 WindowTitleAlign = ImVec2(0.5f, 0.5f);
		float ChildRounding = 0.0f;
		float ChildBorderSize = 1.0f;
		float PopupRounding = 0.0f;
		float PopupBorderSize = 1.0f;
		ImVec2 FramePadding = ImVec2(6.0f, 6.0f);
		float FrameRounding = 0.0f;
		float FrameBorderSize = 0.0f;
		ImVec2 ItemSpacing = ImVec2(12.0f, 6.0f);
		ImVec2 ItemInnerSpacing = ImVec2(6.0f, 3.0f);
		ImVec2 CellPadding = ImVec2(12.0f, 6.0f);
		float IndentSpacing = 20.0f;
		float ColumnsMinSpacing = 6.0f;
		float ScrollbarSize = 12.0f;
		float ScrollbarRounding = 0.0f;
		float GrabMinSize = 12.0f;
		float GrabRounding = 0.0f;
		float TabRounding = 0.0f;
		float TabBorderSize = 0.0f;
		float TabMinWidthForCloseButton = 0.0f;
		ImVec2 ButtonTextAlign = ImVec2(0.5f, 0.5f);
		ImVec2 SelectableTextAlign = ImVec2(0.0f, 0.0f);
		float LogSliderDeadzone = 4;
	    };
	    
	    namespace Colors {
		ImVec4 Text = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
		ImVec4 TextDisabled = ImVec4(0.2745098173618317f, 0.3176470696926117f, 0.4509803950786591f, 1.0f);
		ImVec4 WindowBg = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 ChildBg = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 PopupBg = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 Border = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
		ImVec4 BorderShadow = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 FrameBg = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 FrameBgHovered = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
		ImVec4 FrameBgActive = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 TitleBg = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TitleBgActive = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TitleBgCollapsed = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 MenuBarBg = ImVec4(0.09803921729326248f, 0.105882354080677f, 0.1215686276555061f, 1.0f);
		ImVec4 ScrollbarBg = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 ScrollbarGrab = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 ScrollbarGrabHovered = ImVec4(0.1568627506494522f, 0.168627455830574f, 0.1921568661928177f, 1.0f);
		ImVec4 ScrollbarGrabActive = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 CheckMark = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 SliderGrab = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 SliderGrabActive = ImVec4(0.5372549295425415f, 0.5529412031173706f, 1.0f, 1.0f);
		ImVec4 Button = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 ButtonHovered = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 1.0f);
		ImVec4 ButtonActive = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 Header = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 HeaderHovered = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 1.0f);
		ImVec4 HeaderActive = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 Separator = ImVec4(0.1568627506494522f, 0.1843137294054031f, 0.250980406999588f, 1.0f);
		ImVec4 SeparatorHovered = ImVec4(0.1568627506494522f, 0.1843137294054031f, 0.250980406999588f, 1.0f);
		ImVec4 SeparatorActive = ImVec4(0.1568627506494522f, 0.1843137294054031f, 0.250980406999588f, 1.0f);
		ImVec4 ResizeGrip = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 ResizeGripHovered = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 1.0f);
		ImVec4 ResizeGripActive = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 Tab = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TabHovered = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 TabActive = ImVec4(0.09803921729326248f, 0.105882354080677f, 0.1215686276555061f, 1.0f);
		ImVec4 TabUnfocused = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TabUnfocusedActive = ImVec4(0.0784313753247261f, 0.08627451211214066f, 0.1019607856869698f, 1.0f);
		ImVec4 PlotLines = ImVec4(0.5215686559677124f, 0.6000000238418579f, 0.7019608020782471f, 1.0f);
		ImVec4 PlotLinesHovered = ImVec4(0.03921568766236305f, 0.9803921580314636f, 0.9803921580314636f, 1.0f);
		ImVec4 PlotHistogram = ImVec4(1.0f, 0.2901960909366608f, 0.5960784554481506f, 1.0f);
		ImVec4 PlotHistogramHovered = ImVec4(0.9960784316062927f, 0.4745098054409027f, 0.6980392336845398f, 1.0f);
		ImVec4 TableHeaderBg = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TableBorderStrong = ImVec4(0.0470588244497776f, 0.05490196123719215f, 0.07058823853731155f, 1.0f);
		ImVec4 TableBorderLight = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
		ImVec4 TableRowBg = ImVec4(0.1176470592617989f, 0.1333333402872086f, 0.1490196138620377f, 1.0f);
		ImVec4 TableRowBgAlt = ImVec4(0.09803921729326248f, 0.105882354080677f, 0.1215686276555061f, 1.0f);
		ImVec4 TextSelectedBg = ImVec4(0.2352941185235977f, 0.2156862765550613f, 0.5960784554481506f, 1.0f);
		ImVec4 DragDropTarget = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 NavHighlight = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 NavWindowingHighlight = ImVec4(0.4980392158031464f, 0.5137255191802979f, 1.0f, 1.0f);
		ImVec4 NavWindowingDimBg = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 0.501960813999176f);
		ImVec4 ModalWindowDimBg = ImVec4(0.196078434586525f, 0.1764705926179886f, 0.5450980663299561f, 0.501960813999176f);
            }; 
        };
        
        namespace EmbraceTheDarkness {
            namespace Styles {
		ImVec2 WindowPadding                   = ImVec2(8.00f, 8.00f);
		ImVec2 FramePadding                    = ImVec2(5.00f, 2.00f);
		ImVec2 CellPadding                     = ImVec2(6.00f, 6.00f);
		ImVec2 ItemSpacing                     = ImVec2(6.00f, 6.00f);
		ImVec2 ItemInnerSpacing                = ImVec2(6.00f, 6.00f);
		ImVec2 TouchExtraPadding               = ImVec2(0.00f, 0.00f);
		int IndentSpacing                      = 25;
		int ScrollbarSize                      = 15;
		int GrabMinSize                        = 10;
		int WindowBorderSize                   = 1;
		int ChildBorderSize                    = 1;
		int PopupBorderSize                    = 1;
		int FrameBorderSize                    = 1;
		int TabBorderSize                      = 1;
		int WindowRounding                     = 7;
		int ChildRounding                      = 4;
		int FrameRounding                      = 3;
		int PopupRounding                      = 4;
		int ScrollbarRounding                  = 9;
		int GrabRounding                       = 3;
		int LogSliderDeadzone                  = 4;
		int TabRounding                        = 4;
            };
            
	    namespace Colors {
	        ImVec4 Text                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	  	ImVec4 TextDisabled           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	  	ImVec4 WindowBg               = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
	  	ImVec4 ChildBg                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	  	ImVec4 PopupBg                = ImVec4(0.19f, 0.19f, 0.19f, 0.92f);
	  	ImVec4 Border                 = ImVec4(0.19f, 0.19f, 0.19f, 0.29f);
	  	ImVec4 BorderShadow           = ImVec4(0.00f, 0.00f, 0.00f, 0.24f);
	  	ImVec4 FrameBg                = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	  	ImVec4 FrameBgHovered         = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	  	ImVec4 FrameBgActive          = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	  	ImVec4 TitleBg                = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	  	ImVec4 TitleBgActive          = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	  	ImVec4 TitleBgCollapsed       = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
	  	ImVec4 MenuBarBg              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	  	ImVec4 ScrollbarBg            = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	  	ImVec4 ScrollbarGrab          = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	  	ImVec4 ScrollbarGrabHovered   = ImVec4(0.40f, 0.40f, 0.40f, 0.54f);
	  	ImVec4 ScrollbarGrabActive    = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	 	ImVec4 CheckMark              = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
		ImVec4 SliderGrab             = ImVec4(0.34f, 0.34f, 0.34f, 0.54f);
	 	ImVec4 SliderGrabActive       = ImVec4(0.56f, 0.56f, 0.56f, 0.54f);
	  	ImVec4 Button                 = ImVec4(0.05f, 0.05f, 0.05f, 0.54f);
	  	ImVec4 ButtonHovered          = ImVec4(0.19f, 0.19f, 0.19f, 0.54f);
	  	ImVec4 ButtonActive           = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	  	ImVec4 Header                 = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	  	ImVec4 HeaderHovered          = ImVec4(0.00f, 0.00f, 0.00f, 0.36f);
	  	ImVec4 HeaderActive           = ImVec4(0.20f, 0.22f, 0.23f, 0.33f);
	  	ImVec4 Separator              = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	  	ImVec4 SeparatorHovered       = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	  	ImVec4 SeparatorActive        = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	  	ImVec4 ResizeGrip             = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	  	ImVec4 ResizeGripHovered      = ImVec4(0.44f, 0.44f, 0.44f, 0.29f);
	  	ImVec4 ResizeGripActive       = ImVec4(0.40f, 0.44f, 0.47f, 1.00f);
	  	ImVec4 Tab                    = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	  	ImVec4 TabHovered             = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	  	ImVec4 TabActive              = ImVec4(0.20f, 0.20f, 0.20f, 0.36f);
	  	ImVec4 TabUnfocused           = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	  	ImVec4 TabUnfocusedActive     = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	  	ImVec4 PlotLines              = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	  	ImVec4 PlotLinesHovered       = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	  	ImVec4 PlotHistogram          = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	  	ImVec4 PlotHistogramHovered   = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	  	ImVec4 TableHeaderBg          = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	  	ImVec4 TableBorderStrong      = ImVec4(0.00f, 0.00f, 0.00f, 0.52f);
	  	ImVec4 TableBorderLight       = ImVec4(0.28f, 0.28f, 0.28f, 0.29f);
	  	ImVec4 TableRowBg             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	  	ImVec4 TableRowBgAlt          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
	  	ImVec4 TextSelectedBg         = ImVec4(0.20f, 0.22f, 0.23f, 1.00f);
	  	ImVec4 DragDropTarget         = ImVec4(0.33f, 0.67f, 0.86f, 1.00f);
	  	ImVec4 NavHighlight           = ImVec4(1.00f, 0.00f, 0.00f, 1.00f);
	  	ImVec4 NavWindowingHighlight  = ImVec4(1.00f, 0.00f, 0.00f, 0.70f);
	  	ImVec4 NavWindowingDimBg      = ImVec4(1.00f, 0.00f, 0.00f, 0.20f);
	  	ImVec4 ModalWindowDimBg       = ImVec4(1.00f, 0.00f, 0.00f, 0.35f);
	    
    	    };
	};
        
        namespace Enemymouse {
            namespace Style {
            	float Alpha = 1.0;
		float DisabledAlpha = 1.0f;
		ImVec2 WindowPadding = ImVec2(12.0f, 12.0f);
		float WindowRounding = 3.0f;
		float WindowBorderSize = 0.0f;
		ImVec2 WindowMinSize = ImVec2(20.0f, 20.0f);
		ImVec2 WindowTitleAlign = ImVec2(0.5f, 0.5f);
		float ChildRounding = 3.0f;
		float ChildBorderSize = 1.0f;
		float PopupRounding = 0.0f;
		float PopupBorderSize = 1.0f;
		ImVec2 FramePadding = ImVec2(6.0f, 6.0f);
		float FrameRounding = 3.0f;
		float FrameBorderSize = 0.0f;
		ImVec2 ItemSpacing = ImVec2(12.0f, 6.0f);
		ImVec2 ItemInnerSpacing = ImVec2(6.0f, 3.0f);
		ImVec2 CellPadding = ImVec2(12.0f, 6.0f);
		float IndentSpacing = 20.0f;
		float ColumnsMinSpacing = 6.0f;
		float ScrollbarSize = 12.0f;
		float ScrollbarRounding = 0.0f;
		float GrabMinSize = 20.0f;
		float GrabRounding = 1.0f;
		float TabRounding = 0.0f;
		float TabBorderSize = 0.0f;
		float TabMinWidthForCloseButton = 0.0f;
		ImVec2 ButtonTextAlign = ImVec2(0.5f, 0.5f);
		ImVec2 SelectableTextAlign = ImVec2(0.0f, 0.0f);
            };
            
            namespace Colors {
		ImVec4 Text = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		ImVec4 TextDisabled = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);
		ImVec4 WindowBg = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
		ImVec4 Border = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
		ImVec4 BorderShadow = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		ImVec4 FrameBg = ImVec4(0.00f, 1.00f, 1.00f, 0.18f);
		ImVec4 FrameBgHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
		ImVec4 FrameBgActive = ImVec4(0.00f, 1.00f, 1.00f, 0.66f);
		ImVec4 PlotLines = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
		ImVec4 Tab = ImVec4(0.00f, 1.00f, 1.00f, 0.18f);
		ImVec4 TabHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.60f);
		ImVec4 TabActive = ImVec4(0.00f, 1.00f, 1.00f, 0.60f);
		ImVec4 TitleBg = ImVec4(0.14f, 0.18f, 0.21f, 0.73f);
		ImVec4 TitleBgCollapsed = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
		ImVec4 TitleBgActive = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
		ImVec4 MenuBarBg = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
		ImVec4 ScrollbarBg = ImVec4(0.22f, 0.29f, 0.30f, 0.71f);
		ImVec4 ScrollbarGrab = ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
		ImVec4 ScrollbarGrabHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
		ImVec4 ScrollbarGrabActive = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		ImVec4 Separator = ImVec4(0.00f, 1.00f, 1.00f, 0.65f);
		ImVec4 CheckMark = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
		ImVec4 SliderGrab = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
		ImVec4 SliderGrabActive = ImVec4(0.00f, 1.00f, 1.00f, 0.76f);
		ImVec4 Button = ImVec4(0.00f, 0.65f, 0.65f, 0.46f);
		ImVec4 ButtonHovered = ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
		ImVec4 ButtonActive = ImVec4(0.00f, 1.00f, 1.00f, 0.62f);
		ImVec4 Header = ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
		ImVec4 HeaderHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
		ImVec4 HeaderActive = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
		ImVec4 ResizeGrip = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
		ImVec4 ResizeGripHovered = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
		ImVec4 ResizeGripActive = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		ImVec4 PlotLinesHovered = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		ImVec4 PlotHistogram = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		ImVec4 PlotHistogramHovered = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
		ImVec4 TextSelectedBg = ImVec4(0.00f, 1.00f, 1.00f, 0.22f);
            };
        }; 
    };
};
