public class VHSMovie extends Movie implements VHS{
    private String format;
    private String language;

    public VHSMovie(String initialTitle,
             String[] initialActors,
             String initialDirector,
             String initialFormat,
             String initialLanguage)
    {
       super(initialTitle,initialActors,initialDirector);
        format=initialFormat;
        language=initialLanguage;
    }

    public String getLanguage() {
        return language;
    }

    public String toString() {
        return getTitle()+","+format+","+language;
    }

    public String getFormat()
    {return format;}


}
