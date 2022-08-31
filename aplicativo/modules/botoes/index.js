import { useState, useEffect } from 'react'
import { StyleSheet, Text, View, TouchableOpacity } from 'react-native'
import { MaterialCommunityIcons } from '@expo/vector-icons'

import listaBotoes from './botoes.json'

function Botoes() {
    const [lista, setLista] = useState(listaBotoes)

    const RenderizaBotao = ({ icone, descricao, ativo, pressionado }, i) => (
        <TouchableOpacity style={[estilos.botao]} key={i}>
            <MaterialCommunityIcons size={40} name={icone} color='#292929' />
            <Text style={{ textAlign: 'center' }}>{descricao}</Text>
        </TouchableOpacity>
    )

    return (
        <View style={estilos.container}>
            {
                lista.map(RenderizaBotao)
            }
        </View>
    )
}

const estilos = StyleSheet.create({
    container: {
        flex: 1,
        alignItems: 'center',
        justifyContent: 'center',
        flexDirection: 'row'
    },
    botao: {
        backgroundColor: '#e9e9e9',
        width: 90,
        height: 90,
        alignItems: 'center',
        justifyContent: 'center',
        margin: 5,
        borderRadius: 5
    }
})


export default Botoes