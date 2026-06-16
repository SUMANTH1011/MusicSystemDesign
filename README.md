# Music Player — System Design Example

This repository contains a C++ demonstration of a Music Player application following system-design principles (Facade, Strategy, Factory, Manager patterns).

## Project overview
- Small modular design with headers organized under `core`, `device`, `managers`, `factories`, `models`, `strategies`, and `external`.
- Demonstrates device adapters (Bluetooth, Wired, Headphones), playlist management, and playback strategies (Sequential, Random, Custom Queue).

## Build (Windows, MinGW)
Make sure `g++` (MinGW) is installed and on PATH.

```powershell
g++ -std=c++17 main.cpp -I. -o main.exe
```

## Run
```powershell
./main.exe
```

## Notes
- Headers use simple mock external APIs under `external/` for adapters.
- `main.cpp` runs a demo that connects a Bluetooth device and plays sample songs.

## License
This project is provided as-is for learning and demonstration purposes.

---

Repository: https://github.com/SUMANTH1011/MusicSystemDesign.git
