containerid=$(docker ps  -qf "ancestor=bawkbak/docker-moosrosbridge:01")
echo $containerid
if [ $containerid ] 
then 
    echo "join an existed container"
    docker exec -it $containerid bash
else
    echo "create a new container"
    docker run -itd bawkbak/docker-moosrosbridge:01
fi
