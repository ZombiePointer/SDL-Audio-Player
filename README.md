# SDL-Audio-Player
A basic, single-header implementation of an [SDL Mixer 1.2](https://www.libsdl.org/projects/mixer) WAV file audio player in [SDL2](https://www.libsdl.org/). The player can play both sound effect files and music tracks.

**As far as I'm aware, SDL Mixer is only compatible with sound files saved in the 16-bit WAV format.** If your file is not saved in that format, it may not play correctly.

## How do I use this?
First ensure you have a correctly configured installation of SDL2 and SDL Mixer. The `SDL_Mixer.h` file should be in the include directory of your SDL installation folder. You should also ensure you have properly set up `SDL2_mixer.lib` and included the `SDL2_mixer.dll` file in your project directory.
1. Include the header file **AudioPlayer.h**.
2. Edit the sound effect and music track storage objects to contain the file names of your sound files, as well as the number of total sound effects and tracks.
3. On construction, the files will all be loaded as sound objects and ready for playing.

## Documentation
- [SDL Mixer website and documentation](https://www.libsdl.org/projects/mixer)
- [SDL Mixer Github repo](https://github.com/libsdl-org/SDL_mixer)
