def get_cricket_players():
    return {"Jay","Parul","Kiran","Shyam","Ravi","Mahi"}
def get_badminton_players():
    return {"Raju","Ram","Jay","Parul","Chintu","Jack"}
def get_football_players():
    return {"Jack","Shyam","Bobby","Pinku","Goli","Chintu"}     

def both_cricket_and_badminton():
    cricket_players = get_cricket_players()
    badminton_players = get_badminton_players()
    return cricket_players.intersection(badminton_players)

def either_cricket_or_badminton_not_both():
    cricket_players = get_cricket_players()
    badminton_players = get_badminton_players()
    return ((cricket_players.union(badminton_players))-(cricket_players.intersection(badminton_players)))

def neither_cricket_nor_badminton():
    all_students = {"Raju","Ram","Jay","Parul","Kiran","Shyam","Bobby","Pinku","Goli","Chintu","Jack","Chinnu","Ravi","Mahi"}
    cricket_players = get_cricket_players()
    badminton_players = get_badminton_players()
    return len((all_students) - (cricket_players) - (badminton_players))

def cricket_and_football_not_badminton():
    cricket_players = get_cricket_players()
    football_players = get_football_players()
    badminton_players = get_badminton_players()
    return len(cricket_players.intersection(football_players)- (badminton_players))

print("Students who play both cricket and badminton:",both_cricket_and_badminton())
print("Students who play either cricket or badminton but not both:",either_cricket_or_badminton_not_both())
print("Number of students who play neither cricket nor badminton:",neither_cricket_nor_badminton())
print("Number of students who play cricket and football but not badminton:",cricket_and_football_not_badminton())