#pragma once

#include <iostream>
#include <map>
#include <string>
#include "SDL/include/SDL_mixer.h"

using namespace std;

class AudioPlayer
{
private:

    int MusicVolume = 128;
    int SoundEffectVolume = 128;

    // File locations of the sound effects you want to load.
    const char* SoundEffectFiles[1] = {
      "Sounds/Sound.wav",
    };
    int numberOfSounds = 1;

    map<string, Mix_Chunk*> SoundEffects;

    // File locations of the music tracks you want to load.
    const char* MusicFiles[1] = {
        "Music/Placeholder.wav",
    };
    int numberOfTracks = 1;

    map<string, Mix_Music*> MusicTracks;

public:

    AudioPlayer()
    {
        InitializeMixer();
    }

    void ChangeMusicVolume(int newValue)
    {
        if (newValue < 0 || newValue > 128)
        {
            return;
        }

        MusicVolume = newValue;
        Mix_VolumeMusic(MusicVolume);
    }

    void ChangeSoundEffectVolume(int newValue)
    {
        if (newValue < 0 || newValue > 128)
        {
            return;
        }

        SoundEffectVolume = newValue;
        Mix_Volume(-1, SoundEffectVolume);
    }

    void Destroy()
    {
        SoundEffects.clear();
        MusicTracks.clear();
    }

    int GetMusicVolume()
    {
        return MusicVolume;
    }

    int GetSoundEffectVolume()
    {
        return SoundEffectVolume;
    }

    void InitializeMixer()
    {
        int result = Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 512);
        result = Mix_AllocateChannels(4);

        for (int i = 0; i < numberOfSounds; i++)
        {
            const char* fileName = SoundEffectFiles[i];
            SoundEffects[fileName] = Mix_LoadWAV(fileName);

            if (SoundEffects[fileName] == NULL)
            {
                exit(-1);
            }
        }

        for (int j = 0; j < numberOfTracks; j++)
        {
            const char* fileName = MusicFiles[j];
            MusicTracks[fileName] = Mix_LoadMUS(fileName);

            if (MusicTracks[fileName] == NULL)
            {
                exit(-1);
            }
        }
    }

    void PauseAllSounds()
    {
        Mix_Pause(-1);
    }

    void PauseMusic()
    {
        Mix_PauseMusic();
    }

    void PauseSound(int channel)
    {
        Mix_Pause(channel);
    }

    void PlayMusic(string track)
    {
        Mix_PlayMusic(MusicTracks[track + ".wav"], -1);
    }

    void PlaySound(string sound)
    {
        Mix_PlayChannel(-1, SoundEffects[sound + ".wav"], 0);
    }

    void PlaySoundOnChannel(string sound, int channel)
    {
        Mix_PlayChannel(channel, SoundEffects[sound + ".wav"], 0);
    }

    void ResumeAllSounds()
    {
        Mix_Resume(-1);
    }

    void ResumeMusic()
    {
        Mix_ResumeMusic();
    }

    void ResumeSound(int channel)
    {
        Mix_Resume(channel);
    }

    void StopAllSounds()
    {
        Mix_HaltChannel(-1);
    }

    void StopMusic()
    {
        Mix_HaltMusic();
    }

    void StopSound(int channel)
    {
        Mix_HaltChannel(channel);
    }
};
