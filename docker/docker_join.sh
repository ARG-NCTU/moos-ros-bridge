containerid=$(docker ps  -qf "ancestor=hsuchaochun/moosrosbridge:u18")
echo $containerid
if [ $containerid ] 
then 
    echo "join an existed container"
    docker exec -it $containerid bash
else
    echo "create a new container"
    docker run -itd hsuchaochun/moosrosbridge:u18
fi
