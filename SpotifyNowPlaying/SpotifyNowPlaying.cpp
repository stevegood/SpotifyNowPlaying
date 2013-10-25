#include "SpotifyNowPlaying.h"
using namespace std;

int main() {
	string _now_playing = "Starting up...";
	while (true) {
		EnumWindows(EnumWindowsProc, NULL);
		if (now_playing != _now_playing) {
			_now_playing = now_playing;
			//cout << now_playing.c_str() << endl;
			//cout << "writing title to: " << ExePath() << endl;
			writeToFile(now_playing);
		}
	}
	return 0;
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
	char class_name[80];
	char title[80];
	string _class_name;
	GetClassName(hwnd, class_name, sizeof(class_name));
	GetWindowText(hwnd, title, sizeof(title));

	_class_name = toString(class_name);
	size_t found = _class_name.find("SpotifyMainWindow");
	if (found!=string::npos) {
		now_playing = toString(title);
		now_playing.replace(0,10,"");
	}
	return TRUE;
}

string toString(LPSTR chr) {
	string str(chr);
	return str.c_str();
}

string ExePath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}

void writeToFile(string title) {
	string file_name = ExePath() + "\\spotify_now_playing.txt";
	ofstream file(file_name);
	file << title;
	file.close();
}
