public class DVDMovie extends Movie implements DVD{
private int regionCode;
private String[] audioTracks;
private String[] subtitles;

    DVDMovie(String initialTitle,
             String[] initialActors,
             String initialDirector,
             int initialRegionCode,
             String[] initialAudioTracks,
             String[] initialSubtitles)
    {
        super(initialTitle,initialActors,initialDirector);
        regionCode=initialRegionCode;
        audioTracks=initialAudioTracks;
        subtitles=initialSubtitles;
    }

    @Override //annotation
    public int getRegionCode() {
        return regionCode;
    }

    @Override
    public String[] getAudioTracks() {
        return audioTracks;
    }

    @Override
    public String[] getSubtitles() {
        return subtitles;
    }

    public String toString(){
        return getTitle()+","+regionCode;
    }
}
