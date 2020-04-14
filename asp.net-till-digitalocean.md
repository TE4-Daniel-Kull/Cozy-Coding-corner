1. Börja med att skapa ett konto på docker hub.
   1. Tryck sign up och skapa ditt konto.
   2. Skapa ett repo för din image.  
   3. Skriv in ett namn på repot.
   4.  Sätt repositoryt till "private" om du vill. 
   5.  Tryck "create".

2. Ladda ned en publicerad build av projektet. 
   1. Gå till Azure -> Pipelines -> För api:t välj "Localix-Geolocator-CI-CD".
   2. Välj den senaste succesful körningen.
   3. Gå in på published.
   4. Ladda ned artifakten.

3. Sätt upp filstrukturen och skapa din docker file.
   1. Skapa en ny mapp. Namnet spelar ingen roll.
   2. Dra in zip filen och extrahera innehållet till sin egen sub-map.
   3. Skapa en fil vid namn "Dockerfile" ingen extension.
      - Note: "Dockerfile" behöver (för api:t) ligga parallellt med mappen "Localix.Geolocator.Api". Om mappen heter "Localix.Geolocator.Api (1)" eller liknande, döp om den till "Localix.Geolocator.Api".
   4. Öppna filen "Dockerfile" och skriv in följande ifall du ska sätta up api:t
        ```
        FROM mcr.microsoft.com/dotnet/core/aspnet:3.1
        WORKDIR /app
        COPY Localix.Geolocator.Api/ .
        ENTRYPOINT ["dotnet", "Localix.Geolocator.Api.dll"]
        ```
        1. FROM - Specifierar vilken image från dockerhub av aspnet vårt program använder sig av. 
        2. WORKDIR - Är vårt working directory inuti vår image.
        3. COPY - Kopierar alla filer från mappen Localix.Geolocator.Api in i vår image. "." är vår path i vår image dit filerna ska kopieras.
        4. ENTRYPOINT - Säger åt vår imagen vad vi ska göra när vi skapar en container. I detta fallen kör den kommandot "dotnet" med argumentet "Localix.Geolocator.Api.dll", vilket i detta fallet kommer starta vår api.
4. Builda din image
   1. Gå till docker hub och kopiera namnet på ditt repository. Det brukar stå i formatet username/repository-name. T.ex "marca/localix-api".
   2. Öppna terminalen och navigera till mappen där vår Dockerfile ligger.
   3. Kör `docker build --tag <namnet-på-ditt-repository> .`. Exempel `docker build --tag marca/localix-api .`.
   4. Om du nu kör `docker images` så borde du kunna se din image med namnet som du gav den.
5. Pusha din image
   1. (Om du skapade ett privat repository på dockerhub) Kör `docker login` och skriv in ditt användarnamn och sen lösenord för att få åtkomst till ditt repository.
   2. Kör `docker push <namnet-på-ditt-repository>` för att skicka upp din image till dockerhub. Exempel `docker push marca/localix-api`.
   3. Dubbelkolla på dockerhub att din image blev pushad. Under tags bör det nu finnas en image med taggen latest.
6. Skapa en access token till ditt docker hub konto (Denna kommer användas av digital ocean).
   1. Gå in på ditt konto på dockerhub.
   2. Tryck på ditt konto uppe till höger => Account settings => Security => New access token.
   3. Skriv in en description och tryck "Create".
   4. Spara den genererade token på något ställe som du enkelt kan kopiera den till senare.
7. Sätt upp din "droplet" på digital ocean.
   1. Skapa ett konto på digital ocean.
   2. Tryck Create => Droplets.
   3. Under "Choose an image" välj marketplace och sök på "Docker" och välj den.
   4. Du kan lämna alla inställningar som default. (Men ett tips är att dubbelkolla vilken betalnings plan du vill använda. Det går att skrolla till vänster för billigare alternativ såsom 5$).
   5. Tryck "Create droplet".
   6. Vänta på att dropletten skapas.
8. Starta din container inuti din droplet. (UTAN SSL)
   1. Gå till Droplets och kopiera ip adressen för din droplet.
   2. Ta upp terminalen och ssh:a in till adressen med användaren "root". (Beroende på vilken metod du valde tidigare så får du antingen använda din ssh nyckel eller lösenordet från din epost för att logga in). Exempel kommando `ssh -i <filvägen-till-din-ssh-nyckel> root@12.345.678.90`.
   3. När du är inne i din droplet. Kör `docker login` för att logga in på ditt docker hub konto. I lösenords fältet skriver du in din Access Token som du skapade i tidigare steg.
   4. Kör `docker pull <namnet-på-ditt-repository>` för att ladda ned din image från docker hub.
   5. Till sist kör `docker run --detach --publish 80:80 --name <valfritt-namn-på-containern> <namnet-på-din-image>`. Exempel `docker run --detach --publish 80:80 --name api marca/localix-api`.
      1. `--detach`, står för att processen ska köras i bakgrunden. (Kör kommandot `docker ps`för att se vilka containrar är igång).
      2. `--publish`, den första 80 specifierar porten på ditt program. Den andra :80 specifierar porten på din container.
      3. `--name <custom-name>`, sätter namnet på containern till det namn du specifierar.
      4. `<namnet-på-din-image>`, specifierar vilken image du vill att din container ska starta ifrån.
   6. För att dubbelkolla att containern körs så kan du skriva `docker ps` för att se alla containrar som körs. Nu borde du se att en container finns i listan med samma namn som du gav den i tidigare steg.
   7. Om du nu surfar in på din droplets ip-adress i webbläsaren så bör du nu se din startsida.
   8. Klart! (För att gå ut ur ssh i terminalen, skriv kommandot `exit`).

9. Starta din container inuti din droplet. (MED SSL) // TODO: Check if SSL IS WORKING!
   1. Gå till Droplets och kopiera ip adressen för din droplet.
   2. Ta upp terminalen och ssh:a in till adressen med användaren "root". (Beroende på vilken metod du valde tidigare så får du antingen använda din ssh nyckel eller lösenordet från din epost för att logga in). Exempel kommando `ssh -i <filvägen-till-din-ssh-nyckel> root@12.345.678.90`.
   3. När du är inne i servern, kör `mkdir -p ~/.aspnet/https` för att skapa en map där vi kan förvara vårt aspnet certifikat.
   4. Gå ut ur servern med hjälp av kommandot `exit`.
   6.  Sätt upp ditt certifikat.
       1.  Först dubbelkolla att du är tillbaka på din lokala dator så att du INTE sitter kvar på servern.
       2.  Kör ```dotnet dev-certs https -ep ${HOME}/.aspnet/https/aspnetapp.pfx -p <ditt-custom-certificat-lösenord>```.
       3.  Sedan ```dotnet dev-certs https --trust```.
   7.  Kopiera över ditt certifikat till servern.
       1.  Kör kommandot `scp -i <filvägen-till-din-ssh-nyckel> <filvägen-till-ditt-certifikat> root@12.345.678.90:/root/.aspnet/https/` för att kopiera över certifikatet till servern. Exempel `scp -i ~/.ssh/id_rsa ~/.aspnet/https/aspnetapp.pfx root@12.345.678.90:/root/.aspnet/https/`.
   8.  ssh:a in i servern igen. Exempel kommando `ssh -i <filvägen-till-din-ssh-nyckel> root@12.345.678.90`.
   9.  När du är inne i din droplet. Kör `docker login` för att logga in på ditt docker hub konto. I lösenords fältet skriver du in din Access Token som du skapade i tidigare steg.
   10. Kör `docker pull <namnet-på-ditt-repository>` för att ladda ned din image från docker hub.
   11. Till sist kör `docker run -d -p 80:80 -p 443:443 -e ASPNETCORE_URLS="https://+;http://+" -e ASPNETCORE_HTTPS_PORT=443 -e ASPNETCORE_Kestrel__Certificates__Default__Password=<ditt-custom-certificat-lösenord-här> -e ASPNETCORE_Kestrel__Certificates__Default__Path=/https/aspnetapp.pfx -v ${HOME}/.aspnet/https:/https/ --name <valfritt-namn-på-containern> <namnet-på-din-image>`.
       1.  `-d, --detach`, står för att processen ska köras i bakgrunden. (Kör kommandot `docker ps`för att se vilka containrar är igång).
       2.  `-p, --publish`, den första 80 specifierar porten på ditt program. Den andra :80 specifierar porten på din container.
       3.  `--name <custom-name>`, sätter namnet på containern till det namn du specifierar.
       4.  `<namnet-på-din-image>`, specifierar vilken image du vill att din container ska starta ifrån.
   12. För att dubbelkolla att containern körs så kan du skriva `docker ps` för att se alla containrar som körs. Nu borde du se att en container finns i listan med samma namn som du gav den i tidigare steg.
   13. Om du nu surfar in på din droplets ip-adress i webbläsaren så bör du nu se din startsida.
   14. Klart! (För att gå ut ur ssh i terminalen, skriv kommandot `exit`).