До конца не доделано.

Идея: написать наивную реализацию, т.е. создать класс State раскладки карт, затем запустить BFS, 
который бы у каждой текущей State вызывал метод Proccessing, проверяющий и добавляющий все возможные из него
State`ы к себе в качестве детей. Затем текущий State вернул бы ссылку на массив своих дочерних элементов, которые 
добавятся в очередь. Продолжаем, пока Proccessing не вернёт true.