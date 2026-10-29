def solution(participant, completion):
    count_participant = {}
    
    for name in participant:
        cnt = count_participant.get(name, 0)
        count_participant[name] = cnt+1
    
    count_completion = {}
    
    for name in completion:
        cnt = count_completion.get(name,0)
        count_completion[name] = cnt+1
    answer = ''    
    for name in participant:
        if count_participant[name] != count_completion.get(name,0):
            answer = name
            break
    return answer
