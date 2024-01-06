#object adapter
#а есть ещё class adapter

class SlowDbEngine:
    
    def __init__(self, host, user, password, db):
        pass
    
    def runQuery(self, sql):
        return ["row1", "row2", "row3"]
     
class FastDbEngine:
    
    def __init__(self, connection):        
        pass        
    
    def query(self, sql):
        return range(1, 4)
    
    def fetch(self, result):
        return "row"+str(result)
    
    
class DbAdapter:
        
    def __init__(self, host, user, password, db, type = "fast"):
        self._type = type
        if(type == "slow"):
            self._db = SlowDbEngine(host, user, password, db)
        else:
            self._db = FastDbEngine([host, user, password, db])
    
    def runQuery(self, sql):
        if self._type == "slow":
            return self._db.runQuery(sql)
        else:
            result = self._db.query(sql)                            
            return [self._db.fetch(i) for i in result]
      
if __name__ == '__main__':   
    print(DbAdapter("localhost", "root", "password", "db").runQuery("select * from table"))